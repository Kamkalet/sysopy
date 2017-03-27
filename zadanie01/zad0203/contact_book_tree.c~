#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_book_tree.h"
#include "user.h"
#include <stdbool.h>


struct contact_tree* create_contact_tree(const char* property) {

    contact_tree* tree = malloc( sizeof( struct contact_tree ) );
    tree->left = NULL;
    tree->right = NULL;
    tree->user = NULL;
    tree->parent = NULL;

	if(!strcmp(property,"surname")){
		tree->property_pointer = &compareSurnames;
	}
	else if(!strcmp(property,"birth")){
		tree->property_pointer = &compareBirths;
	}
	else if(!strcmp(property,"email")){
		tree->property_pointer = &compareEmails;
	}
	else if(!strcmp(property,"phone")){
		tree->property_pointer = &comparePhones;
	}
	else {
		free(tree);
		return NULL;
	}

    return tree;

}


int compareSurnames(User* a,struct User* b){
	return strcmp(a->surname,b->surname);
}
int compareBirths(User* a,struct User* b){
	return strcmp(a->date_of_birth,b->date_of_birth);
}
int compareEmails(User* a,struct User* b){
	return strcmp(a->email,b->email);
}
int comparePhones(User* a,User* b){
	return strcmp(a->phone,b->phone);
}

void delete_contact_tree(struct  contact_tree* tree){

	if(tree->left!=NULL) delete_contact_tree(tree->left);
	if(tree->right!=NULL) delete_contact_tree(tree->right);
	deleteUser(tree->user);
	free(tree);

}

void add_user_to_tree(User* user,contact_tree* tree){
// if tree is empty
	if (tree->user == NULL){
		tree->user = user;
	}
	else{

		contact_tree* contact = malloc(sizeof(struct contact_tree));
		contact->user = user;
		contact->left = NULL;
		contact->right = NULL;
		contact->property_pointer = tree->property_pointer;
		contact->parent = NULL;

		while(true){
			if ((*(tree->property_pointer))(tree->user,user) > 0){
				if (tree->right == NULL){
					tree->right = contact;
					contact->parent = tree;
					return;
				}
				tree = tree->right;
			}
			else{
				if (tree->left == NULL){
					tree->left = contact;
					contact->parent = tree;
					return;
				}
				tree = tree->left;
			}
		}


	}
}

struct contact_tree* delete_user_from_tree(User* user,contact_tree* tree){

	contact_tree* root = tree;
	while(tree != NULL){

		if (!strcmp(tree->user->surname,user->surname)
            && !strcmp(tree->user->date_of_birth,user->date_of_birth)
            && !strcmp(tree->user->email,user->email)
            && !strcmp(tree->user->phone,user->phone))
                break;

		if ( (*(tree->property_pointer) ) (tree->user,user) > 0){

			if (tree->right == NULL)
                return root;
            else
                tree = tree->right;


        }
		else{

			if (tree->left == NULL)
                return root;
            else
                tree = tree->left;


        }

	}

	deleteUser(tree->user);

	if (tree->right == NULL && tree->left == NULL && tree->parent!=NULL){

		if(tree->parent->left == tree) tree->parent->left = NULL;
		else tree->parent->right = NULL;
		free(tree);
		return root;

	}
	else if (tree->right == NULL && tree->left == NULL && tree->parent==NULL){

		free(tree);
		return NULL;

	}
	else if (tree->right == NULL && tree->parent!=NULL){

		if(tree->parent->left == tree) tree->parent->left = tree->left;
		else tree->parent->right = tree->left;
		free(tree);
		return root;

	}
	else if (tree->left == NULL && tree->parent!=NULL){

		if(tree->parent->left == tree) tree->parent->left = tree->right;
		else tree->parent->right = tree->right;
		free(tree);
		return root;

	}
	else if (tree->right == NULL && tree->parent==NULL){

		tree = tree->left;
		free(tree->parent);
		tree->parent = NULL;
		return tree;

	}
	else if (tree->left == NULL && tree->parent==NULL){
		tree = tree->right;
		free(tree->parent);
		tree->parent = NULL;
		return tree;
	}
	else {

		contact_tree* successor = find_successor(tree);
		successor->left = tree->left;
		tree->left->parent = successor;

		if (successor->parent->left == successor){

			successor->parent->left= successor->right;
			if(successor->right != NULL) successor->right->parent = successor->parent;

		}
		else{

			successor->parent->right = successor->right;
			if(successor->right != NULL) successor->right->parent = successor->parent;

		}

		successor->right = tree->right;
		tree->parent = tree->parent;
		free(tree);
		return successor;

	}
}

contact_tree* find_successor(struct contact_tree* contact){

	return min_left_subtree(contact->right);

}

contact_tree* min_left_subtree(struct contact_tree* contact){

	if (contact->left != NULL) return min_left_subtree(contact->left);
	return contact;

}

contact_tree* sort_tree(const char* property,contact_tree* tree){

	contact_tree* sortedTree = create_contact_tree(property);

	if(!strcmp(property,"surname") || !strcmp(property,"date_of_birth")
        || !strcmp(property,"email") || !strcmp(property,"phone") ){

		sort(sortedTree,tree);

	}
	else{

		free(sortedTree);
		return tree;

	}
	return sortedTree;

}

void sort(struct contact_tree* sortedTree, contact_tree* tree){

	if (tree->left != NULL){
		sort(sortedTree,tree->left);
	}
	if (tree->right != NULL){
		sort(sortedTree,tree->right);
	}
	add_user_to_tree(tree->user,sortedTree);
	deleteUser(tree->user);
	free(tree);

}






