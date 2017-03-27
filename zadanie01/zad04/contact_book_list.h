#include "user.h"
#ifndef CONTACT_BOOK_LIST_H_INCLUDED
#define CONTACT_BOOK_LIST_H_INCLUDED

typedef struct contact_list {

    User * user;
    struct contact_list * next;
    struct contact_list * prev;

} contact_list;

struct contact_list* create_contact_list();
void delete_contact_list(contact_list* list);
void add_user(User* a, contact_list* list);
contact_list* delete_user(User* a, contact_list* list);
User* find_User(const char* name, const char* surname,const char* date_of_birth,const char* email,const char* phone, contact_list* list);
struct contact_list* sort_list(const char* property, contact_list* list);


#endif // CONTACT_BOOK_LIST_H_INCLUDED
/* "
Biblioteka powinna umozliwiac:

- tworzenie i usuwanie ksiazki kontaktowej

- dodanie i usuniecie  kontaktu do/z ksiazki (bez utraty innych kontaktow i bez wyciekow pamieci)

- wyszukiwanie elementu w ksiazce

- sortowanie/przebudowanie ksiazki wg wybranego pola (Nazwisko, Data urodzenia, email, telefon) " */
