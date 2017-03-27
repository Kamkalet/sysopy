#include "user.h"
#include <string.h>
#include <stdlib.h>

void deleteUser(User* p){
	free(p->name);
	free(p->surname);
	free(p->date_of_birth);
	free(p->email);
	free(p->phone);
	free(p->address);
	free(p);
}

struct User* createUser(const char* name,const char* surname,const char* date_of_birth,const char* email,const char* phone,const char* address){

    User* user = (User*) malloc(sizeof(struct User));

	user->name = malloc(50*sizeof( *(user->name) ));
	strcpy(user->name , name);

    user->surname = malloc(50*sizeof( *(user->surname) ) );
	strcpy(user->surname , surname);

	user->date_of_birth = malloc(15*sizeof( *(user->date_of_birth) ) );
	strcpy(user->date_of_birth , date_of_birth);

	user->email = malloc(50*sizeof( *(user->email) ) );
	strcpy(user->email, email);

	user->phone = malloc(50*sizeof( *(user->phone) ) );
	strcpy(user->phone , phone);

	user->address = malloc(50*sizeof( *(user->address) ) );
	strcpy(user->address, address);

	return user;

}
