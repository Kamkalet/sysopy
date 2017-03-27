#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_book_list.h"
#include "user.h"
#include <stdbool.h>

#define bool int
#define true 1
#define false 0

struct contact_list* create_contact_list(){

    contact_list* list = malloc( sizeof( struct contact_list ) );
    list->prev = NULL;
    list->next = NULL;
    list->user = NULL;

    return list;

}

void delete_contact_list(contact_list* list){

    contact_list* curr=list;
    while(curr->prev != NULL){

        curr = curr->prev;

    }
    while(curr->next!= NULL){

        contact_list* tmp = curr;
        curr = curr->next;
        deleteUser(curr->user);
        free(tmp);

    }

}
void add_user(User* a, contact_list* list){

        while(list->next != NULL){

            list = list->next;

        }
        if (list->user == NULL){

            list->user = a;

        }
        else{

            contact_list* contact = malloc(sizeof(struct contact_list));
            contact->prev = list;
            list->next = contact;
            contact->next = NULL;
            list = contact;
            list->user = a;

        }


}

contact_list* delete_user(User* a, contact_list* list){

        while(list->prev != NULL){

            list = list->prev;

        }
        contact_list* tmp = list;
        while(list->next != NULL){

            if(list->user == a){


                if(list->prev !=NULL){

                    list->prev->next=list->next;
                    if(list->next != NULL)
                        list->next->prev = list->prev;

                }
                else{

                    list->next->prev = NULL;
                    tmp = list->next;

                }

                deleteUser(list->user);
                free(list);
                list = tmp;
                break;


            }

            list = list->next;


        }
        return list;

}

User* find_User(const char* name, const char* surname,const char* date_of_birth,const char* email,const char* phone, contact_list* list){

	while(list->prev != NULL){
		list = list->prev;
	}
	while(list != NULL){
		if (!strcmp(list->user->surname,surname) && !strcmp(list->user->date_of_birth,date_of_birth) && !strcmp(list->user->email,email)
		&& !strcmp(list->user->phone,phone)) return list->user;
		list = list->next;
	}
	return NULL;
}

contact_list* sort_list(const char* property, contact_list* list){

    contact_list* current_last = list;
    while(current_last->next != NULL){
            current_last = current_last->next;
        }

    contact_list* current_first = list;
    while(current_first->prev != NULL){
            current_first = current_first->prev;
        }


    if(strcmp(property,"surname")==0){

       bool swapped = false;
       // loop through all numbers
       while(current_first != current_last) {

          swapped = false;
          contact_list* current = current_first;
          while(current != current_last){
              if(strcmp(current->user->surname,
              current->next->user->surname)>0){

                    if(current->next == current_last) current_last = current;
                    swap(current, current->next);
                    current = current->prev;
                    swapped = true;
              }

                current = current->next;


          }
        while(current_first->prev != NULL){
					current_first = current_first->prev;
        }
        if(!swapped) break;


          current_last = current_last->prev;

       }

    }
    else if(strcmp(property,"date_of_birth")==0){


       bool swapped = false;
       // loop through all numbers
       while(current_first != current_last) {

          swapped = false;
          contact_list* current = current_first;
          while(current != current_last){

              if(strcmp(current->user->date_of_birth,
              current->next->user->date_of_birth)>0){

                    if(current->next == current_last) current_last = current;
                    swap(current, current->next);
                    current = current->prev;
                    swapped = true;
              }

                current = current->next;


          }
        while(current_first->prev != NULL){
					current_first = current_first->prev;
        }
        if(!swapped) break;


          current_last = current_last->prev;

       }



    }
    else if(strcmp(property,"email")==0){

       bool swapped = false;
       // loop through all numbers
       while(current_first != current_last) {

          swapped = false;
          contact_list* current = current_first;
          while(current != current_last){

              if(strcmp(current->user->email,
              current->next->user->email)>0){

                    if(current->next == current_last) current_last = current;
                    swap(current, current->next);
                    current = current->prev;
                    swapped = true;
              }

                current = current->next;


          }
        while(current_first->prev != NULL){
					current_first = current_first->prev;
        }
        if(!swapped) break;


          current_last = current_last->prev;

       }

    }
    else if(strcmp(property,"phone")==0){

       bool swapped = false;
       // loop through all numbers
       while(current_first != current_last) {

          swapped = false;
          contact_list* current = current_first;
          while(current != current_last){

              if(strcmp(current->user->phone,
              current->next->user->phone)>0){

                    if(current->next == current_last) current_last = current;
                    swap(current, current->next);
                    current = current->prev;
                    swapped = true;
              }

                current = current->next;


          }
        while(current_first->prev != NULL){
					current_first = current_first->prev;
        }
        if(!swapped) break;


          current_last = current_last->prev;

       }

    }
    else{

        return current_first;
    }

    list = current_first;
    return list;


}

void swap(contact_list* a, contact_list* b){

    a->next = b->next;
    if (b->next!=NULL) b->next->prev = a;
    b->prev = a->prev;
    b->next = a;
    a->prev = b;
    if (b->prev!= NULL) b->prev->next = b;


}


void printUser(contact_list* contact){
	printf("Name: %s\n", contact->user->name);
	printf("Surname: %s\n", contact->user->surname);
	printf("Birth: %s\n", contact->user->date_of_birth);
	printf("Email: %s\n", contact->user->email);
	printf("Phone: %s\n", contact->user->phone);
	printf("Address: %s\n", contact->user->address);
}

void printContactList(contact_list* list){
	while(list->prev!= NULL) list=list->prev;
	while(list != NULL ){
        if(list->user !=NULL)
		printUser(list);
		list = list->next;
	}
}
/*

void sort_list(const char* property, contact_list* list)*/
