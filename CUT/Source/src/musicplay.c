#include <stdio.h>
#include <stdlib.h>
#include <struct.h>
#include <main.h>


/*****************************************************************************************
Sprint Name:Juck Box
Function Name :displaySonglist (used to display all song in songlist)

******************************************************************************************/

int displaySonglist()
{
    FILE *file;
    file = fopen("../data/songlist.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    //Music music[TRACK_NAME];

else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, file)) {
            column = 0;
            row++;
 
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
 
            // Splitting the data
            char* value = strtok(buffer, ", ");
 
            while (value) {
                // Column 1
                if (column == 0) {
                    printf("trackId :");
                }
 
                // Column 2
                if (column == 1) {
                    printf("\t trackName :");
                }
 
                // Column 3
                if (column == 2) {
                    printf("\t artistName :");
                }
               // Column 4
                if (column == 3) {
                    printf("\t filePath :");
                }
 
 
                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }
 
            printf("\n");
        }
 
        // Close the file
        fclose(file);
    }
    return 0;
}



/*****************************************************************************************
Sprint Name:Juck Box
Function Name :addSongPlaylist (used to add song in playlist)

*******************************************************************************************/

int addSongPlaylist()
{
    FILE *fp = fopen("../data/playlist.csv", "a+");
    int trackId;
    char trackName[TRACK_NAME];
    char artistName[ARTIST_NAME];
    char filePath[FILE_Path];
    printf("\nEnter trackID\n");
    scanf("%d", &trackId);
    printf("\nEnter track Name\n");
    scanf("%s", &trackName);
    printf("\nEnter artistName\n");
    scanf("%s", &artistName);
    printf("\nEnter filepath\n");
    scanf("%s", &filePath);

    fprintf(fp, "%d,%s,%s,%s\n", trackId,
            trackName, artistName,filePath);
    printf("song are Added Successfully\n");
    fclose(fp);
    return 0;
}




/*****************************************************************************************
Sprint Name:Juck Box
Function Name :deleteSongPlaylist (used to delete song in playlist)

*******************************************************************************************/

int deleteSongPlaylist()
{
    FILE *fp1;
    FILE *fp2;

    char ch;

   int line = 0;
   
    int temp = 1;

    fp1 = fopen("../data/playlist.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1))
    {
        ch = getc(fp1);
    }
    rewind(fp1);

    printf("\nEnter line number to delete the Song: ");
    scanf("%d", &line);

    fp2 = fopen("temp.csv", "w");

    while (!feof(fp1))
    {
        ch = getc(fp1);

        if (ch == '\n')
            temp++;

        if (temp != line)
            putc(ch, fp2);
    }

    fclose(fp1);

    fclose(fp2);

    remove("../data/playlist.csv");
    rename("temp.csv", "../data/playlist.csv");

    printf("\n song deleted Successfully:\n");

    fp1 = fopen("../data/playlist.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1))
    {
        ch = getc(fp1);
       
    }

    fclose(fp1);

    printf("\n");

    return 0;
}


/*****************************************************************************************
Sprint Name:Juck Box
Function Name :displayPlaylist (used to display songs in playlist)

*******************************************************************************************/

int displayPlayList()
{
	FILE *file2;
    file2 = fopen("../data/playlist.csv", "r");
    if (file2 == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    //Music music[TRACK_NAME];

else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer1[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer1,
                     1024, file2)) {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
	    // Splitting the data
            char* value = strtok(buffer1, ", ");

            while (value) {
                // Column 1
                if (column == 0) {
                    printf("trackId :");
                }

                // Column 2
                if (column == 1) {
                    printf("\t trackName :");
                }

                // Column 3
                if (column == 2) {
                    printf("\t artistName :");
                }
               // Column 4
                if (column == 3) {
                    printf("\t filePath :");
                }


                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }

            printf("\n");
        }

        // Close the file
        fclose(file2);
    }
    return 0;

}
/*****************************************************************************************
Sprint Name:Juck Box
Function Name :playsong (used to play songs in playlist)

*******************************************************************************************/



 int playSong()
{
  printf("\n Song is playing!!!!!!!!");
}

/***************************************/

