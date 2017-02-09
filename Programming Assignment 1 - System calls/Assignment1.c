#include <syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
//Matt Noblett
//Programming Assignment 1
//Wolffe - Winter 2017
//1/18/17
int main(void){
    int ID2, ID3;
    char *ID1;
    char hostname[128];


    //Getting the Login Name
    ID1 = getlogin();
    printf("Login Name: %s\n", ID1);
    //Getting the User ID
    ID2 = getuid();
    printf("User ID: %1d\n", ID2);
    //Getting the Group ID
    ID3 = getgid();
    printf("GID is: %1d\n", ID3);
    //Getting the Host Name of the Computer
    gethostname(hostname, sizeof hostname);
    printf("Host is: %s\n", hostname);
    //Create the struct from the getpwent man page. 
    struct passwd *p;
    int i = 0;
    //While loop to go through only the first 5 entries. 
    while (i < 5){
        p = getpwent();
        printf("Entry %i: %s\n", i, p->pw_name);
        //Increment the counter
        i++;
    }
    char userinput[20];
    char *path;
    //Asking the user to input the Environment Variable they want to use
    printf("Please input an Environment Variable: ");
    scanf("%s", userinput);
    path = getenv(userinput);
    //Simple check to see if the Variable is null or not, and to print out the correct response. `
    if(path == NULL){
        printf("That environment variable does not exist\n");
    }else{
    printf("Value of the Variable: %s\n", path);
    }
    return(0);

}

