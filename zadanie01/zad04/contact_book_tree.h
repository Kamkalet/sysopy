#include "user.h"
#ifndef CONTACT_BOOK_TREE_H_INCLUDED
#define CONTACT_BOOK_TREE_H_INCLUDED

typedef struct contact_tree {

    int (*property_pointer)(User* a,User* b);
    User * user;
    struct contact_tree * left;
    struct contact_tree * right;
    struct contact_tree * parent;

} contact_tree;

struct contact_tree* create_contact_tree(const char* value);
void delete_contact_tree(contact_tree* tree);
void add_user_to_tree(User* a, contact_tree* tree);
contact_tree* delete_user_from_tree(User* a, contact_tree* tree);
//void find_User_tree(User* a, contact_tree* tree);
contact_tree* find_successor(struct contact_tree* contact);
contact_tree* min_left_subtree(struct contact_tree* contact);
contact_tree* sort_tree(const char* property,contact_tree* tree);
void sort(contact_tree* sortedTree, contact_tree* tree);

int compareSurnames(User* a,struct User* b);

int compareBirths(User* a,struct User* b);

int compareEmails(User* a,struct User* b);

int comparePhones(User* a,User* b);

#endif // CONTACT_BOOK_TREE_H_INCLUDED

/* "
Biblioteka powinna umozliwiac:

- tworzenie i usuwanie ksiazki kontaktowej

- dodanie i usuniecie  kontaktu do/z ksiazki (bez utraty innych kontaktow i bez wyciekow pamieci)

- wyszukiwanie elementu w ksiazce

- sortowanie/przebudowanie ksiazki wg wybranego pola (Nazwisko, Data urodzenia, email, telefon) " */
