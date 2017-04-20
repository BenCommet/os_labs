#include <stdio.h> 
#include <dirent.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <errno.h>

int main() 
{ 
   DIR *dirPtr; 
   struct dirent *entryPtr; 
   struct stat mystat;

   dirPtr = opendir (".");
    while ((entryPtr = readdir (dirPtr))) {

      if (stat (entryPtr->d_name, &mystat) < 0) {
        perror ("huh?  there is ");
        exit(1);
      }
	
      if(entryPtr->d_name[0] != '.')
        printf ("%-20s Size: %d\n", entryPtr->d_name, (int)mystat.st_size);
    }   

closedir (dirPtr); 
   return 0; 
}
