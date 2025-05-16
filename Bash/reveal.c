#include "reveal.h"

int cmp(const void *a, const void *b) {
    const struct dirent *da = (const struct dirent *)a;
    const struct dirent *db = (const struct dirent *)b;
    return strcmp(da->d_name, db->d_name);
}

void reveal(char*  directory, int flags[2]){
    char* copy = (char*)malloc(MAX);
    char* current_path = (char*)malloc(MAX);
    DIR *dp;
    struct dirent* de;
    struct dirent de_copies[MAX];
    struct stat sb;
    int idx = 0;
    char path[MAX];

    strcpy(copy, directory);
    getcwd(current_path, MAX);
    if(hop(copy, 0) == -1){
        return ;
    }

    dp = opendir(".");
    if(dp == NULL){
        printf(RED"Could not open directory!\n"ESC );
        return ;
    }

    while((de = readdir(dp)) != NULL){
        if(flags[1] == 0 && de->d_name[0] == '.')
            continue;

        de_copies[idx] = (*de);
        idx++;
    }

    qsort(de_copies, idx, sizeof(struct dirent), cmp);
    for(int i = 0;i < idx;i++){
        char timebuf[64];
        mode_t mode;

        snprintf(path, sizeof(path), "./%s", de_copies[i].d_name);
        strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", localtime(&sb.st_mtime));

        if(stat(path, &sb) == -1){
            perror("stat");
            continue;
        }

        mode = sb.st_mode;
        if(flags[0]){
            struct passwd *pw;
            struct group  *gr;

            pw = getpwuid(sb.st_uid);
            gr= getgrgid(sb.st_gid);

            if (S_ISREG(mode)) printf("-");
            else if (S_ISDIR(mode)) printf("d");
            else if (S_ISLNK(mode)) printf("l");
            else if (S_ISCHR(mode)) printf("c");
            else if (S_ISBLK(mode)) printf("b");
            else if (S_ISFIFO(mode)) printf("p");
            else if (S_ISSOCK(mode)) printf("s");
            else printf("?");

            printf( (mode & S_IRUSR) ? "r" : "-");
            printf( (mode & S_IWUSR) ? "w" : "-");
            printf( (mode & S_IXUSR) ? "x" : "-");
            printf( (mode & S_IRGRP) ? "r" : "-");
            printf( (mode & S_IWGRP) ? "w" : "-");
            printf( (mode & S_IXGRP) ? "x" : "-");
            printf( (mode & S_IROTH) ? "r" : "-");
            printf( (mode & S_IWOTH) ? "w" : "-");
            printf( (mode & S_IXOTH) ? "x" : "-");

            printf(" %lu", sb.st_nlink);
            printf(" %s", pw ? pw->pw_name : "???");
            printf(" %s", gr ? gr->gr_name : "???");
            printf(" %5lld", (long long)sb.st_size);
            printf(" %s ", timebuf);
        }

        if(S_ISDIR(mode)) printf(MGN"%s\n"ESC, de_copies[i].d_name);
        else if(mode & S_IXUSR) printf(GRN"%s\n"ESC, de_copies[i].d_name);
        else printf("%s\n", de_copies[i].d_name);
        fflush(stdout);
    }

    hop(current_path, 0);
}

void process_reveal(char* command){
    char* copy = strdup(command);
    char* token = strtok(copy, " ");
    char* next;
    int flags[2] = {0};
    bool first_token = true;
    bool directory_exist = false;

    while(token){
        next = strtok(NULL, " ");
        if(first_token){
            first_token = false;
            if(next == NULL){
                strcpy(token, ".");
                reveal(token, flags);
            }
            else if(next[0] != '-')
                directory_exist = true;
        }

        else if(directory_exist == false){
            if(token[1] == '\0'){
                printf(RED"No such file or directory!\n"ESC);
                return ;
            }
            
            for(int i=1;i<strlen(token);i++){
                if(token[i] == 'l')
                    flags[0] = 1;
                
                else if(token[i] == 'a')
                    flags[1] = 1;

                else{
                    printf(RED"Invalid Flag!\n"ESC);
                    return ;
                }
            }

            if(next == NULL){
                strcpy(token, ".");
                reveal(token, flags);
            }

            else if(next[0] != '-')
                directory_exist = true;
        }

        else
            reveal(token, flags);

        token = next;
    }
}