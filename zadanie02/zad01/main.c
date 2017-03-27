#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void generate(char *filename, int size_of_record, int amount);
void shuffle_lib(char *filename, int size_of_record, int amount);

int main(int argc, char *argv[])
{

	if( argc != 4 ) { // check if user entered 2 arguments ( without main.o sciezki )
		printf("\nInvalid number of arguments supplied!!!\n");
		return 1;
	}

	generate( argv[1], atoi(argv[2]) , atoi(argv[3]) );
	//shuffle_lib(argv[1]);

    printf("Hello world!\n");
    return 0;
}

void generate(char *filename, int size_of_record, int amount){

    char *path_to_r = "/dev/random";
    FILE* file = fopen(path_to_r, "r+");
    FILE* records = fopen(filename, "w+");

    if( file == NULL || records == NULL ){

        printf("Opening Error");
        exit(-1);

    }

    char *buffer = malloc(size_of_record);

    int i = 0;

    for( ; i < amount ; i++ ){

        if(fread(buffer, size_of_record, 1, file) >  0 ){

            fwrite(buffer, size_of_record, 1, records);

        }

    }

    close(file);
    close(records);

}

void shuffle_lib(char *filename, int size_of_record, int amount){

    FILE* records = fopen(filename, "r+");

    if( records == NULL ){

        printf("Opening Error");
        exit(-1);

    }


/*for i from n−1 downto 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]*/

    int i = amount - 1;

    for( ; i > 0 ; i-- ){



    }


}







