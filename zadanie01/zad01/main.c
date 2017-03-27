#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "contact_book_list.h"


int main()
{

    User* a = createUser("Kamil","Kaleta","lol2","lol","lol","św Faustyny 31");
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
    printContactList(listaA);



  //  printf("Hello world!\n");
    return 0;
}
