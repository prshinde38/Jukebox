#ifndef __MAIN_H__
#define __MAIN_H__
#import <string.h>

#define TRACK_NAME 40
#define ARTIST_NAME 40
#define FILE_Path 256
#define max 20


typedef struct
{
    int trackId;
    char trackName[TRACK_NAME];
    char artistName[ARTIST_NAME];
    char filePath[FILE_Path];

} Music;

#endif