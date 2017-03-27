#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>

struct stat file_stat(const char *filename, struct stat st);
void diveIntoDirTree(const char *name, int level, int size);
char* get_permissions(struct stat st);
char* get_date_last_modified(struct stat st);

int main( int argc, char *argv[] )
{

	if( argc != 3 ) { // check if user entered 2 arguments ( without main.o sciezki )
		printf("\nInvalid number of arguments supplied!!!\n");
		return 1;
	}

    char *user_path = argv[1];
   // if(user_path[0]=='/'){
        diveIntoDirTree( argv[1] , 0 , atoi(argv[2]) );
  //  }

    return 0;
}

void diveIntoDirTree(const char *name, int level, int size) // absolute_path - (to directory, not file)
{
    DIR *dir;

    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;
    if (!(entry = readdir(dir)))
        return;

    do {

        char path[1024];
        int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
        path[len] = 0; // end with null

        if (entry->d_type == DT_DIR) {

            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            printf("%*s[%s]\n", level*2, "", entry->d_name);
            diveIntoDirTree(path, level + 1, size);

        }
        else{


            char actualpath [PATH_MAX+1];
            char *ptr;

            ptr = realpath(path, actualpath); // niepewne

            struct stat st = file_stat(ptr,st);

            long long int size_of_file = st.st_size;

            if(size_of_file <= size) {

                char *permissions = get_permissions(st);
                char *date = get_date_last_modified(st);
                printf("%*s- %s %s %d", level*2, "", entry->d_name, ptr, size_of_file);
                printf(" %s %s\n", permissions, date);
                free(permissions);
                free(date);

            }

        }

    } while (entry = readdir(dir)); // until end of directory
    closedir(dir);
}

char* get_date_last_modified(struct stat st){

    char *date = malloc(sizeof(char)*20);
    strftime(date, 20, "%d-%m-%y", localtime(&(st.st_ctime)));

    return date;

}

char* get_permissions(struct stat st){ // stackoverflow from

    char *toreturn = malloc(sizeof(char)*11) ;
    strcpy(toreturn, (S_ISDIR(st.st_mode)) ? "d" : "-");
    strcat(toreturn, (st.st_mode & S_IRUSR) ? "r" : "-");
    strcat(toreturn, (st.st_mode & S_IWUSR) ? "w" : "-");
    strcat(toreturn, (st.st_mode & S_IXUSR) ? "x" : "-");
    strcat(toreturn, (st.st_mode & S_IRGRP) ? "r" : "-");
    strcat(toreturn, (st.st_mode & S_IWGRP) ? "w" : "-");
    strcat(toreturn, (st.st_mode & S_IXGRP) ? "x" : "-");
    strcat(toreturn, (st.st_mode & S_IROTH) ? "r" : "-");
    strcat(toreturn, (st.st_mode & S_IWOTH) ? "w" : "-");
    strcat(toreturn, (st.st_mode & S_IXOTH) ? "x" : "-");

    return toreturn;

}

struct stat file_stat(const char *path, struct stat st) {

    if ((fstatat(1,path, &st, AT_SYMLINK_NOFOLLOW) == 0 ) ) // first argument is ignored if path is absolute
        return st;


}
