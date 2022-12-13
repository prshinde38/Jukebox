#include <stdio.h>
#include <stdlib.h>
#include <struct.h>
#include <main.h>


/*************************************************************************************
Sprint Name:Juck Box
Function Name :Load file read and append mode.

*************************************************************************************/

int importSongs(int choice)
{
    FILE *file, *file2;
    file = fopen("../data/songlist.csv", "r");
    file2 = fopen("../data/playlist.csv", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    Music music[TRACK_NAME];
    int read = 0;
    int records = 0;
    do
    {
        read = fscanf(file, "%d,%s,%s,%s\n", &music[records].trackId, music[records].trackName, music[records].artistName, music[records].filePath);

        if (read == 4)
            records++;

        if (read != 4 && !feof(file))
        {
            printf("File format incorrect\n");
            return 1;
        }

        if (ferror(file))
        {
            printf("Error Reading file\n");
            return 1;
        }
    }
      while (!feof(file));
    fclose(file);
    // printf("Records read is %d\n", records);
    for (int i = 0; i < records; i++)
    {
        // printf("%d %s %d %d\n", features[i].featureId, features[i].featureName, features[i].priority, features[i].cost);
        if (music[i].trackId == choice)
        {
            fprintf(file2, "%d,%s,%s,%s\n", music[i].trackId, music[i].trackName, music[i].artistName, music[i].filePath);
            printf("song is Succesfully added to the Release List.\n");
        }
    }
    fclose(file2);
}



/*************************************************************************************
Sprint Name:Juck Box
Function Name :MenuSystem

*************************************************************************************/


void main()  
{
  int ch = 0;
  do
    {
      printf ("********************************************************\n");
      printf ("*****************  Welcome to JukeBox ******************\n");
      printf ("********************************************************\n");
      printf("\n1: Display Songlist");
      printf("\n2: Add Song to Playlist ");
      printf("\n3: Remove song from playlist ");
      printf("\n4: Display playlist");
      printf("\n5: Play song from playlist");
      printf("\n6: Exit");
      printf ("\n******************************************************\n");

                    
                 printf("\n Enter your choice :");
                    scanf("%d", &ch);

                    switch (ch)
                    {
                    case 1:
                        displaySonglist();
                        break;
                    case 2:
                        addSongPlaylist();
                        break;

                    case 3:
                         deleteSongPlaylist();
                         break;
                  
                     case 4:
                        displayPlayList();
                        break;
                      
                      case 5:  
                        playSong();
                        break;
                     
                      case 6:
                      exit(0);
                      
                    }
                }
               while ( ch != 6);
  }
        
