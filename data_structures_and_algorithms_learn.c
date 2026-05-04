#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef enum{OK=1, ERROR=0} Status;
typedef enum{true=1, false=0} bool;
typedef void* Elemtype;

typedef struct{
    char name[50];
    char number[20];
}Contactinfo;

typedef struct Node{
    Contactinfo data;
    struct Node* next;
}Node;

Node* pool = NULL;
int count;

Node* initContactBook();
Status addPerson(Node* Book, char *name , char* number);
Status findPerson(Node* Book, char* name, char* e);
Status changePerson(Node* Book, char* name, char* newnumber);
Status delPerson(Node* Book, char* name);
void displayContactBook(Node* Book);
Status freeAll(Node* Book);

Node* initContactBook(){
    Node* Book = (Node*)malloc(sizeof(Node));
    if(Book == NULL){
        return NULL;
    }
    Book->next = NULL;

    return Book;
}

Status addPerson(Node* Book , char *name ,char* number){
    if(Book == NULL){
        return ERROR;
    }
    Node* newnode;
    if(pool != NULL){
        newnode = pool;
        pool = pool->next;
        count--;
    }else{
        Node* newnode = (Node*)malloc(sizeof(Node));
        if(newnode == NULL){
            return ERROR;
        }
    }
    strcpy(newnode->data.name , name);
    strcpy(newnode->data.number , number);
    newnode->next = NULL;

    Node* p = Book;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = newnode;

    return OK;
}

Status findPerson(Node* Book, char *name, char* e){
    if(Book == NULL){
        return ERROR;
    }
    Node* p;
    p = Book->next;
    if(p==NULL){
        return ERROR;
    }
    while(p != NULL && strcmp(p->data.name, name)!=0 ){
        p = p->next;
    }
    if(p == NULL){
        return ERROR;
    }
    if(strcmp(p->data.name, name)==0){
        strcpy(e, p->data.number);
    }
    return OK;
}
Status changePerson(Node* Book, char* name, char* newnumber){
    if(Book == NULL){
        return ERROR;
    }
    Node* p;
    p = Book->next;
    if(p == NULL){
        return ERROR;
    }
    while(p != NULL && strcmp(p->data.name, name) != 0){
        p = p->next;
    }
    if(p == NULL){
        return ERROR;
    }
    if(strcmp(p->data.name, name) == 0){
        strcpy(p->data.number , newnumber);
    }
    return OK;
}

Status delPerson(Node* Book, char *name){
    if(Book == NULL){
        return ERROR;
    }
    Node* p = Book;
    if(p->next==NULL){
        return ERROR;
    }
    while(p->next != NULL && strcmp(p->next->data.name, name)!=0){
        p = p->next;
    }
    if(p->next == NULL){
        return ERROR;
    }
    if(strcmp(p->next->data.name, name)==0){
        Node* temp = p->next;
        p->next = temp->next;
        if(count < MAX){
            if(pool != NULL){
                
            }
        }else{
            free(temp);
        }
        
        return OK;
    }
}

void displayContactBook(Node* Book){
    if(Book == NULL){
        return ;
    }
    Node* p;
    p = Book->next;
    if(p == NULL){
        return ;
    }   
    while(p != NULL){
        printf("%s : %s\n", p->data.name , p->data.number);
        p = p->next;
    }
}

Status freeAll(Node* Book){
    if(Book == NULL){
        return OK;
    }
    Node* p = Book;
    Node* temp;

    while(p != NULL){
        temp = p->next;
        free(p);
        p = temp;
    }
    return OK;
}
int main(){
    Node* Book = initContactBook();
    
    addPerson(Book, "mary" , "111222333");
    addPerson(Book, "mike" , "222333366");

    delPerson(Book, "mary");
    addPerson(Book, "bsh" , "88828282828");
    addPerson(Book, "GAI", "99302903002");

    changePerson(Book,"GAI", "666666666");
    displayContactBook(Book);

    freeAll(Book);

    return 0;
}