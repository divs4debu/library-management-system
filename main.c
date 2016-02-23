#include <stdio.h>
#include "hash.h"

DB  db;

void ask_pass(){
	char password[15];
	printf("Please enter new password : ");
	scanf("%s", password);
	while(!set_password(&db, password)){
		printf("\nPassword is of invalid format."\
		"\nPlease enter a valid password of length"\
		" between 8 and 15 characters with no spaces"\
		"\nYou can type \'^cancel\' to cancel the password modification.\n\n");
		fgets(password, 15, stdin);
		if(strcmp(password, "^cancel")==0)return;
	}
}

void print_books(){
	//Print all the entered books
	int i;
	for(i = 0; i < db.library.book_count; i++){
		struct Book b = db.library.books[db.library.keys[i]];
		printf("%-20s%-20s%-20s\t%d\n", b.title, b.author, b.publisher, b.id);
	}
}

void print_test(int* a, int size){
	int i = 0;
	for(i = 0; i < size; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
}

int main(){
	int i = 0;
	if(load(&db)==0){
		printf("Database load failed. Terminating");
		return 0;
	}

	printf("%s\n", db.password);
	char* fn = "14peb049";

	//delete_book(&db, find_book(&db, "YUBLGSRC"));
	
	/*if(strcmp(db.password, "0000")==0){
		ask_pass();
	}*/
	print_books();
	struct Book *found = find_book(&db, "MKAWER");
	if(found!=NULL)
		printf("id %s\n", found->title);
	struct Book book = {"MKAWER", "J.K. Rowling", "Bloomsbury", 0, 20};
	printf("%d\n", add_book(&db, &book));
	printf("%d\n", db.library.book_count);
	printf("\n%d\n", verify_fn(fn));
	
	return 0;
}
