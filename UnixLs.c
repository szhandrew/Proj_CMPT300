#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>


void ls()
{
    DIR *dir_p;
    struct dirent *dir;
    
    dir_p = opendir("/Users/ShanZhaohui/Desktop/review_final");
    dir = readdir(dir_p);
    
    while(dir !=NULL){
        printf("%s\n",dir->d_name);
        dir = readdir(dir_p);
    }

    closedir(dir_p);
}


void ls_l()
{
    DIR *dir_p;
    struct dirent *dir;
    
    dir_p = opendir("/Users/ShanZhaohui/Desktop/review_final");
    //dir_p = opendir("/Users/ShanZhaohui");
    dir = readdir(dir_p);
    
    
    
    while (dir != NULL)
    {
        
//        if(dir->d_name[0]=='.')
//            dir = readdir(dir_p);
//        
//        else
//        {
        
        
        // to print the file permission
        struct stat buf;
        stat(dir->d_name, &buf);
        
        
        //to convert the st_mode from decimalism to octonary
        // and showing as r=4 w=2 x=1
        
        printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
        printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
        printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
        printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
        printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
        printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
        printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
        printf( (buf.st_mode & S_IROTH) ? "r" : "-");
        printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
        printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
        //printf("%s\n",Convert_8(buf.st_mode));
        //Convert_8(buf.st_mode);
        
        // print the number of hardlinks
        printf("\t%d", buf.st_nlink);
        
        // print the username of the file owner
        struct passwd *pw;
        pw = getpwuid(buf.st_uid);
        printf("\t%s", pw->pw_name);
        
        //print the group name the owner belongs to
        struct group *g;
        g=getgrgid(buf.st_gid);
        printf("\t%s", g->gr_name);
        
        //print the size of the file in bytes
        printf("\t%lld", buf.st_size);
        
        
        // print the date and time the file was last modified
        time_t t = buf.st_mtime;
        struct tm lt;
        localtime_r(&t, &lt);
        char timebuf[80];
        strftime(timebuf, sizeof(timebuf), "%c", &lt);
        
        printf("\t%s", timebuf);
        
        // to print the filename
        printf("\t%s\n",dir->d_name);
        printf("\n");
        
            dir = readdir(dir_p);
    
    }
    
    closedir(dir_p);

}


void ls_i()
{
    DIR *dir_p;
    struct dirent *dir;
    
    dir_p = opendir("/Users/ShanZhaohui/Desktop/review_final");
    dir = readdir(dir_p);
    
    while(dir !=NULL){

        //print the inode
        printf("\t%llu", dir->d_ino);
        
        // print the file name
        printf("\t%s\n",dir->d_name);
        dir = readdir(dir_p);
    }
    
    closedir(dir_p);

}


void ls_R()
{
    DIR *dir_p;
    struct dirent *dir;
    
    dir_p = opendir("/Users/ShanZhaohui/Desktop/review_final");
    dir = readdir(dir_p);
    
    
    while(dir !=NULL){
        // print the file name
        printf("\t%s\n",dir->d_name);
        dir = readdir(dir_p);
    }
    rewinddir(dir_p);
    
    while( (dir=readdir(dir_p)) != NULL)
    {
        if(dir->d_name[0]=='.')
            dir = readdir(dir_p);
        
        else if(dir->d_type==4)
        {
            printf("\n\t%s: \n",dir->d_name);
            DIR *drp;
            struct dirent *dr;

            drp=opendir("/Users/ShanZhaohui/Desktop/review_final/untitled_folder");
        
            //drp=opendir(strcat("/",dir->d_name));
            dr=readdir(drp);
            
            while(dr != NULL){
                
                printf("\t%s\n",dr->d_name);
                dr=readdir(drp);
            }
            closedir(drp);}
    }
    
    closedir(dir_p);
}


void li_il()
{
    DIR *dir_p;
    struct dirent *dir;
    
    dir_p = opendir("/Users/ShanZhaohui/Desktop/review_final");
    //dir_p = opendir("/Users/ShanZhaohui");
    dir = readdir(dir_p);
    
    
    
    while (dir != NULL)
    {
        
        //        if(dir->d_name[0]=='.')
        //            dir = readdir(dir_p);
        //
        //        else
        //        {
        
        
        // to print the file permission
        struct stat buf;
        stat(dir->d_name, &buf);
        
        // to print the inode at the front
        printf("%llu", dir->d_ino);
        
        
        //to convert the st_mode from decimalism to octonary
        // and showing as r=4 w=2 x=1
        printf("   ");
        printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
        printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
        printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
        printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
        printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
        printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
        printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
        printf( (buf.st_mode & S_IROTH) ? "r" : "-");
        printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
        printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
        //printf("%s\n",Convert_8(buf.st_mode));
        //Convert_8(buf.st_mode);
        
        // print the number of hardlinks
        printf("%5d", buf.st_nlink);
        
        // print the username of the file owner
        struct passwd *pw;
        pw = getpwuid(buf.st_uid);
        printf("   ");
        printf("%5s", pw->pw_name);
        
        //print the group name the owner belongs to
        struct group *g;
        g=getgrgid(buf.st_gid);
        printf("   ");
        printf("%5s", g->gr_name);
        
        //print the size of the file in bytes
        printf("%5lld", buf.st_size);
        
        
        // print the date and time the file was last modified
        time_t t = buf.st_mtime;
        struct tm lt;
        localtime_r(&t, &lt);
        char timebuf[80];
        strftime(timebuf, sizeof(timebuf), "%c", &lt);
        
        printf("   ");
        printf("%s", timebuf);
        
        // to print the filename
        printf("   ");
        printf("%s\n",dir->d_name);
        printf("\n");
        
        dir = readdir(dir_p);
        
    }
    
    closedir(dir_p);

}


void lR_Rl()
{
    DIR *dir_p;
    struct dirent *dir;
    
    dir_p = opendir("/Users/ShanZhaohui/Desktop/review_final");
    //dir_p = opendir("/Users/ShanZhaohui");
    dir = readdir(dir_p);
    
    
    
    while (dir != NULL)
    {
        
        //        if(dir->d_name[0]=='.')
        //            dir = readdir(dir_p);
        //
        //        else
        //        {
        
        
        // to print the file permission
        struct stat buf;
        stat(dir->d_name, &buf);
        
        
        //to convert the st_mode from decimalism to octonary
        // and showing as r=4 w=2 x=1
        
        printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
        printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
        printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
        printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
        printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
        printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
        printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
        printf( (buf.st_mode & S_IROTH) ? "r" : "-");
        printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
        printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
        //printf("%s\n",Convert_8(buf.st_mode));
        //Convert_8(buf.st_mode);
        
        // print the number of hardlinks
        printf("\t%d", buf.st_nlink);
        
        // print the username of the file owner
        struct passwd *pw;
        pw = getpwuid(buf.st_uid);
        printf("\t%s", pw->pw_name);
        
        //print the group name the owner belongs to
        struct group *g;
        g=getgrgid(buf.st_gid);
        printf("\t%s", g->gr_name);
        
        //print the size of the file in bytes
        printf("\t%lld", buf.st_size);
        
        
        // print the date and time the file was last modified
        time_t t = buf.st_mtime;
        struct tm lt;
        localtime_r(&t, &lt);
        char timebuf[80];
        strftime(timebuf, sizeof(timebuf), "%c", &lt);
        
        printf("\t%s", timebuf);
        
        // to print the filename
        printf("\t%s\n",dir->d_name);
        printf("\n");
        
        dir = readdir(dir_p);
        
    }
    
    // reset to initial
    rewinddir(dir_p);
    
    while( (dir=readdir(dir_p)) != NULL)
    {
        if(dir->d_name[0]=='.')
            dir = readdir(dir_p);
        
        else if(dir->d_type==4)
        {
            printf("\n%s: \n",dir->d_name);
            DIR *drp;
            struct dirent *dr;
            
            drp=opendir("/Users/ShanZhaohui/Desktop/review_final/untitled_folder");
            
            //drp=opendir(strcat("/",dir->d_name));
            dr=readdir(drp);
            
            while(dr != NULL){
                
                struct stat buf;
                stat(dr->d_name, &buf);
                
                //printf("   ");
                printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
                printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
                printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
                printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
                printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
                printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
                printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
                printf( (buf.st_mode & S_IROTH) ? "r" : "-");
                printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
                printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
                
                // print the number of hardlinks
                printf("%5d", buf.st_nlink);
                
                // print the username of the file owner
                struct passwd *pw;
                pw = getpwuid(buf.st_uid);
                printf("   ");
                printf("%5s", pw->pw_name);
                
                //print the group name the owner belongs to
                struct group *g;
                g=getgrgid(buf.st_gid);
                printf("   ");
                printf("%5s", g->gr_name);
                
                //print the size of the file in bytes
                printf("%5lld", buf.st_size);
                
                
                // print the date and time the file was last modified
                time_t t = buf.st_mtime;
                struct tm lt;
                localtime_r(&t, &lt);
                char timebuf[80];
                strftime(timebuf, sizeof(timebuf), "%c", &lt);
                
                printf("   ");
                printf("%s", timebuf);
                
                // to print the filename
                printf("   ");
                printf("%s\n",dr->d_name);
                printf("\n");
                
                dr = readdir(dir_p);
                
                
                //printf("\t%s\n",dr->d_name);
                dr=readdir(drp);
            }
            closedir(drp);}
    }
    
    closedir(dir_p);
}

void iR_Ri()
{
    DIR *dir_p;
    struct dirent *dir;
    
    dir_p = opendir("/Users/ShanZhaohui/Desktop/review_final");
    dir = readdir(dir_p);
    
    
    while(dir !=NULL){
        //print the inode
        printf("%llu", dir->d_ino);
        // print the file name
        printf("\t%s\n",dir->d_name);
        dir = readdir(dir_p);
    }
    rewinddir(dir_p);
    
    while( (dir=readdir(dir_p)) != NULL)
    {
        if(dir->d_name[0]=='.')
            dir = readdir(dir_p);
        
        else if(dir->d_type==4)
        {
            printf("\n\t%s: \n",dir->d_name);
            DIR *drp;
            struct dirent *dr;
            
            drp=opendir("/Users/ShanZhaohui/Desktop/review_final/untitled_folder");
            
            //drp=opendir(strcat("/",dir->d_name));
            dr=readdir(drp);
            
            while(dr != NULL){
                
                printf("%llu", dr->d_ino);
                
                printf("\t%s\n",dr->d_name);
                dr=readdir(drp);
            }
            closedir(drp);}
    }
    
    closedir(dir_p);
}


void liR_lRi()
{
    DIR *dir_p;
    struct dirent *dir;
    
    dir_p = opendir("/Users/ShanZhaohui/Desktop/review_final");
    //dir_p = opendir("/Users/ShanZhaohui");
    dir = readdir(dir_p);
    
    
    
    while (dir != NULL)
    {
        
        //        if(dir->d_name[0]=='.')
        //            dir = readdir(dir_p);
        //
        //        else
        //        {
        
        
        // to print the file permission
        struct stat buf;
        stat(dir->d_name, &buf);
        
        // to print the inode at the front
        printf("%llu", dir->d_ino);
        
        
        //to convert the st_mode from decimalism to octonary
        // and showing as r=4 w=2 x=1
        printf("   ");
        printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
        printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
        printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
        printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
        printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
        printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
        printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
        printf( (buf.st_mode & S_IROTH) ? "r" : "-");
        printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
        printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
        //printf("%s\n",Convert_8(buf.st_mode));
        //Convert_8(buf.st_mode);
        
        // print the number of hardlinks
        printf("%5d", buf.st_nlink);
        
        // print the username of the file owner
        struct passwd *pw;
        pw = getpwuid(buf.st_uid);
        printf("   ");
        printf("%5s", pw->pw_name);
        
        //print the group name the owner belongs to
        struct group *g;
        g=getgrgid(buf.st_gid);
        printf("   ");
        printf("%5s", g->gr_name);
        
        //print the size of the file in bytes
        printf("%5lld", buf.st_size);
        
        
        // print the date and time the file was last modified
        time_t t = buf.st_mtime;
        struct tm lt;
        localtime_r(&t, &lt);
        char timebuf[80];
        strftime(timebuf, sizeof(timebuf), "%c", &lt);
        
        printf("   ");
        printf("%s", timebuf);
        
        // to print the filename
        printf("   ");
        printf("%s\n",dir->d_name);
        printf("\n");
        
        dir = readdir(dir_p);
        
    }
    
    rewinddir(dir_p);
    
    while( (dir=readdir(dir_p)) != NULL)
    {
        if(dir->d_name[0]=='.')
            dir = readdir(dir_p);
        
        else if(dir->d_type==4)
        {
            printf("\n%s: \n",dir->d_name);
            DIR *drp;
            struct dirent *dr;
            
            drp=opendir("/Users/ShanZhaohui/Desktop/review_final/untitled_folder");
            
            //drp=opendir(strcat("/",dir->d_name));
            dr=readdir(drp);
            
            while(dr != NULL){
                
                struct stat buf;
                stat(dr->d_name, &buf);
                
                //print the inode
                printf("%llu", dr->d_ino);
                
                
                printf("   ");
                printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
                printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
                printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
                printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
                printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
                printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
                printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
                printf( (buf.st_mode & S_IROTH) ? "r" : "-");
                printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
                printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
                
                // print the number of hardlinks
                printf("%5d", buf.st_nlink);
                
                // print the username of the file owner
                struct passwd *pw;
                pw = getpwuid(buf.st_uid);
                printf("   ");
                printf("%5s", pw->pw_name);
                
                //print the group name the owner belongs to
                struct group *g;
                g=getgrgid(buf.st_gid);
                printf("   ");
                printf("%5s", g->gr_name);
                
                //print the size of the file in bytes
                printf("%5lld", buf.st_size);
                
                
                // print the date and time the file was last modified
                time_t t = buf.st_mtime;
                struct tm lt;
                localtime_r(&t, &lt);
                char timebuf[80];
                strftime(timebuf, sizeof(timebuf), "%c", &lt);
                
                printf("   ");
                printf("%s", timebuf);
                
                // to print the filename
                printf("   ");
                printf("%s\n",dr->d_name);
                printf("\n");
                
                dr = readdir(dir_p);
                
                
                //printf("\t%s\n",dr->d_name);
                dr=readdir(drp);
            }
            closedir(drp);}
    }

    
    closedir(dir_p);

}

int main()
{
    
    printf("%s\n", "Please enter a command, enter quit to terminate");
    char word[8];
    printf("%s", "Enter a command: ");
    //fgets(word, sizeof(word), stdin);
    scanf("%s", word);
    
    while(strcmp(word, "quit") !=0){
    
        if(strcmp(word,"ls")==0)
            ls();
    
        if(strcmp(word,"ls-l")==0)
            ls_l();
    
        if(strcmp(word,"ls-i")==0)
            ls_i();
    
        if(strcmp(word,"ls-R")==0)
            ls_R();
        
        if(strcmp(word,"ls-li")==0)
            li_il();
        
        if(strcmp(word,"ls-il")==0)
            li_il();
        
        if(strcmp(word,"ls-lR")==0)
            lR_Rl();
        
        if(strcmp(word,"ls-Rl")==0)
            lR_Rl();
        
        if(strcmp(word,"ls-iR")==0)
            iR_Ri();
        
        if(strcmp(word,"ls-Ri")==0)
            iR_Ri();
        
        if(strcmp(word,"ls-liR")==0)
            liR_lRi();
        
        if(strcmp(word,"ls-lRi")==0)
            liR_lRi();
        
        if(strcmp(word,"ls-ilR")==0)
            liR_lRi();
        
        if(strcmp(word,"ls-iRl")==0)
            liR_lRi();
        
        if(strcmp(word,"ls-Rli")==0)
            liR_lRi();
        
        if(strcmp(word,"ls-Ril")==0)
            liR_lRi();
        
        
        for(int i=0; i<8; i++)
            word[i]=NULL;
        
        
        printf("%s", "Enter a command: ");
        scanf("%s", word);
    
    }
    
    return 0;
}




