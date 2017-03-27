CC=gcc
CFLAGS=-c -Wall
OBJECTS = contact_book_list.o contact_book_tree.o user.o

all: libstatic libshared

libstatic: contact_book_list.c contact_book_tree.c user.c
	$(CC) $(CFLAGS) $^
	ar -cr $@.a $(OBJECTS)

libshared: contact_book_list.c contact_book_tree.c user.c
	$(CC) $(CFLAGS) -fPIC $^ 
	$(CC) -shared -fPIC -o $@.so $(OBJECTS)


clean:
	rm -f *.a *.o *.so
