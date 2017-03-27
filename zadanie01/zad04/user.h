#ifndef USER_INCLUDED
#define USER_INCLUDED


    typedef struct User
    {
        char* name;
        char* surname;
        char* date_of_birth;
        char* email;
        char* phone;
        char* address;

    } User;

    void deleteUser(User* user);
    struct User* createUser(const char* name,const char* surname,const char* date_of_birth,const char* email,const char* phone,const char* address);



#endif // USER_INCLUDED
