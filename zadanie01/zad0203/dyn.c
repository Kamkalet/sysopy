#include "../zad01/contact_book_tree.h"
#include "../zad01/contact_book_list.h"
#include <stdio.h>
#include <time.h> // clock i CLOCK_PER_SEC
#include <sys/times.h> //dla times
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include <stdlib.h>


 char *names[] = {"Ricky", "Kud", "Celyna", "Draco", "Ewcia", "Uber", "Gandalf",
        "Guy", "Kamil", "Anna", "Karolincia", "Lukasz", "Mon", "Nicolas", "Nicola", "Ericson",
        "Gay", "Is", "Tweety", "Moria", "Steven", "", "Zenoby"};

 char *surnames[] = {"Kaleta", "Kowalski", "Rostowski", "Pomaska", "Gert", "Hejowsky", "Malfoy",
        "Thor", "Odhin", "Growlithe", "Beepery", "Snow", "Storm", "Podgorski", "Lehnon", "Mammooth",
        "Wolski", "Saryusz", "Tusk", "Merkel", "Trump", "Faggins", "Karananski"};

 char *births[] = {"1991-02-24", "1934-01-15", "1984-01-14", "1995-10-15", "1914-11-10", "2030-02-14", "1591-05-25",
        "1917-08-01", "1963-01-01", "1988-17-13", "1392-04-21", "1988-01-15", "1941-09-21", "1986-01-17", "1971-01-15", "2030-04-09",
        "1918-11-19", "1995-10-10", "2709-07-14", "2102-02-12", "1994-04-24", "1961-12-01", "1995-12-12","1985-05-01"};

 char *emails[] = {"@onet.pl", "@gmail.pl", "@eestec.pl", "@interia.pl", "@o2.pl", "@wp.pl", "@example.com"};

 char *numbers[] = {"423534123","1543555234","247354234","23423323","65765434","5234546543","267663456","752315524",
 "8412323234","2755325239","424324387623","5653235234","24154324234","2353233423","6573232434","5236644543"};

 char *addresses[] = {"High Street", "Station Road", "Main Street", "Park Road", "Church Road", "Church Street", "London Road",
        "Victoria Road", "Green Lane", "Manor Road", "Church Lane", "Park Avenue", "The Avenue", "The Crescent", "Queens Road", "New Road",
        "Grange Road", "Kings Road", "Kingsway", "Windsor Road", "Highfield Road", "Mill Lane", "Alexander Road","York Road"};

 int NAMES = 23;
 int SURNAMES = 23;
 int BIRTHS = 24;
 int EMAILS = 7;
 int NUMBERS = 16;
 int ADDRESSES = 24;
 int LIST_SIZE = 1000;


void checkTimes(struct tms *prevTimes, clock_t *prevReal, struct tms *firstTimes, clock_t *firstReal);

int main()
{

void* library = dlopen("libshared.so", RTLD_LAZY

	char *error;

/*
   if (!library) {
	printf("Blad otwarcia");
       fprintf(stderr, "%s\n", dlerror());
       return 1;
   }*/

	struct contact_list* (*create_contact_list)();
	create_contact_list = dlsym(library, "create_contact_list");



   error = dlerror();   
   if (error != NULL) {
       fprintf(stderr, "%s\n", error);
       return 1;
   }

	

	struct User* (*createUser)(const char* name,const char* surname,const char* date_of_birth,const char* email,const char* phone,const char* address);
	createUser = dlsym(library, "createUser");

    struct contact_list* (*add_user)(struct User* user,struct contact_list* list);
    add_user = dlsym(library, "add_user");

    struct User* (*find_User)(const char* surname,const char* date_of_birth,const char* email,const char* phone,struct contact_list* list);
    find_User = dlsym(library, "find_User");

    struct contact_list* (*delete_user)(struct User* user,struct contact_list* list);
    delete_user = dlsym(library, "delete_user");

    void (*delete_contact_list)(struct contact_list* list);
    delete_contact_list = dlsym(library, "delete_contact_list");

    struct contact_list* (*sort_list)(const char* value,struct contact_list* list);
    sort_list = dlsym(library, "sort_list");

//################################TREE##################################################################3

    struct contact_tree* (*create_contact_tree)(const char* value);
    create_contact_tree = dlsym(library, "create_contact_tree");

    struct contact_tree* (*add_user_to_tree)(struct User* somebody,struct contact_tree* tree);
    add_user_to_tree = dlsym(library, "add_user_to_tree");

    struct User* (*find_User_tree)(const char* surname,const char* date_of_birth,const char* email,const char* phone,struct contact_tree* tree);
    find_User_tree = dlsym(library, "find_User_tree");

    struct contact_tree* (*delete_user_from_tree)(struct User* user,struct contact_tree* tree);
    delete_user_from_tree = dlsym(library, "delete_user_from_tree");

    void (*delete_contact_tree)(struct contact_tree* tree);
    delete_contact_tree = dlsym(library, "delete_contact_tree");

    struct contact_tree* (*sort_tree)(const char* value,struct contact_tree* tree);
    sort_tree = dlsym(library, "sort_tree");

//##################################################################################################3
 struct tms prevTimes;
     clock_t prevReal;
     struct tms firstTimes;
     clock_t firstReal;

      prevTimes.tms_stime = -1;

    checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);
     printf("List of %d elements.\n", LIST_SIZE);
     User* sb1;
     User* sb2;
     contact_list* l = create_contact_list();
     srand(time(NULL));
     char* name;
     char* surname;
     char* birth;
     char* email;
     char* phone;
     char* address;
     int i = 0;
    for (; i < LIST_SIZE-2; i++) {
        name = names[rand() % NAMES];
        surname = surnames[rand() % SURNAMES];
        birth = births[rand() % BIRTHS];
        email = emails[rand() % EMAILS];
        phone = numbers[rand() % NUMBERS];
        address = addresses[rand() % ADDRESSES];
        sb1 = createUser(name,surname,birth,email,phone,address);
        add_user(sb1,l);
    }


       

    checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);
    printf("Adding 2 contacts to list.\n");
    sb1 = createUser("Kamil","Kaleta","1903-01-01","kamkalet@gmail.com","889278400","Faustyny");
    add_user(sb1,l);
    sb1 = createUser("Kamil","Kaleta2","2100-04-12","fullbringer@gmail.com","612345653","Faust");
    add_user(sb1,l);

    checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

    printf("Sorting the list by birth.\n");
    l = sort_list("date_of_birth",l);
    checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);


    printf("Finding youngest contact in the list. \n");
    sb1 = find_User("Kaleta","1903-01-01","kamkalet@gmail.com","889278400",l);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

	printf("Finding oldest contact in the list. \n");
    sb2 = find_User("Kaleta2","2100-04-12","fullbringer@gmail.com","612345653",l);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

	printf("Deleting youngest contact from the list.\n");
	delete_user(sb1,l);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

	printf("Deleting oldest contact from the list.\n");
	l = delete_user(sb2,l);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

	printf("Deleting the list.\n");
	delete_contact_list(l);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

	printf("##############################################################\n");


	prevTimes.tms_stime = -1;

	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

    printf("Creating the tree of %d elements.\n", LIST_SIZE-2);
	contact_tree* tree = create_contact_tree("surname");
	i = 0;
    for (; i < LIST_SIZE-2; i++) {
        name = names[rand() % NAMES];
        surname = surnames[rand() % SURNAMES];
        birth = births[rand() % BIRTHS];
        email = emails[rand() % EMAILS];
        phone = numbers[rand() % NUMBERS];
        address = addresses[rand() % ADDRESSES];
        sb1 = createUser(name,surname,birth,email,phone,address);
        add_user_to_tree(sb1,tree);
    }

    checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);
    printf("Adding 2 contacts to tree.\n");
    sb1 = createUser("Kamil","Kaleta","1902-01-01","kamkalet@gmail.com","889278400","asdad");
	add_user_to_tree(sb1,tree);
	sb2 = createUser("Kamil","Kaleta","2017-01-01","kamkalet@gmail.com","889278400","daad");
	add_user_to_tree(sb2,tree);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);


	printf("Sorting the tree by birth.\n");
    tree = sort_tree("date_of_birth", tree);
    checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

    printf("Finding root contact in the tree. \n");
    sb1 = find_User_tree("Kaleta","1902-01-01","kamkalet@gmail.com","889278400",tree);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

	printf("Finding leaf contact in the tree. \n");
    sb2 = find_User_tree("Kaleta","2017-01-01","kamkalet@gmail.com","889278400", tree);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

	printf("Deleting leaf contact from the tree.\n");
	tree = delete_user_from_tree(sb2,tree);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);


	printf("Deleting root contact from the tree.\n");
	tree = delete_user_from_tree(sb2,tree);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);

	printf("Deleting the tree.\n");
	delete_contact_tree(tree);
	checkTimes(&prevTimes, &prevReal, &firstTimes, &firstReal);



    /*User* a = createUser("Kamil","Kaleta","lol2","lol","lol","św Faustyny 31");
    User* b = createUser("Pamil","Daran","lol3","lol","lol","św Faustyny 31");
    User* c = createUser("Pamil","Celinowska","lol1","lol","lol","św Faustyny 31");
    User* d = createUser("Pamil","Aaba","lol1","lol","lol","św Faustyny 31");
    User* e = createUser("Pamil","ŻAnatylana","lol1","lol","lol","św Faustyny 31");
    contact_list* lista = create_contact_list();
    add_user(a, lista);
    add_user(b, lista);
    add_user(c, lista);
    add_user(d, lista);
    add_user(e, lista);
   // printf(lista->user->surname);
 //   printf(lista->next->user->surname);

    contact_list* listaA = sort_list("surname",lista);
    printContactList(listaA);*/

  //  printf("Hello world!\n");
    return 0;
}

#define CLK sysconf(_SC_CLK_TCK)

    void checkTimes(struct tms *prevTimes, clock_t *prevReal,
            struct tms *firstTimes, clock_t *firstReal) {

        struct tms now;
        times(&now);
        clock_t nowReal = clock();
        if (prevTimes->tms_stime == -1) {

            *firstTimes = now;
            *firstReal = nowReal;

        } else {

            printf("\nFrom the first check:\t\tR %.6f\tS %.6f\tU %.6f",
                    ((double) (nowReal - *(firstReal))) / CLOCKS_PER_SEC,
                    ((double) (now.tms_stime - firstTimes->tms_stime)) / CLK,
                    ((double) (now.tms_utime - firstTimes->tms_utime)) / CLK);

            printf("\nFrom the previous check:\tR %.6f\tS %.6f\tU %.6f",
                    ((double) (nowReal - *(prevReal))) / CLOCKS_PER_SEC,
                    ((double) (now.tms_stime - prevTimes->tms_stime)) / CLK,
                    ((double) (now.tms_utime - prevTimes->tms_utime)) / CLK);

        }
        printf("\nTime:\t\t\t\tR %.6f\tS %.6f\tU %.6f\n\n",
                ((double) nowReal) / CLOCKS_PER_SEC,
                ((double) now.tms_stime) / CLK,
                ((double) now.tms_utime) / CLK);

        *prevReal = nowReal;
        *prevTimes = now;

    }

