#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Symbol {
    char name[50];
    char type[20];
    int scope;
    struct Symbol *next;
} Symbol;

Symbol* hashTable[SIZE];
int hash(char *str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }
    return sum % SIZE;
}
Symbol* createSymbol(char *name, char *type, int scope) {
    Symbol *newSymbol = (Symbol*) malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    strcpy(newSymbol->type, type);
    newSymbol->scope = scope;
    newSymbol->next = NULL;
    return newSymbol;
}

// Insert a symbol into the symbol table
void insert(char *name, char *type, int scope) {
    int index = hash(name);
    Symbol *newSymbol = createSymbol(name, type, scope);
    
    if (hashTable[index] == NULL) {
        hashTable[index] = newSymbol;
    } else {
        Symbol *temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSymbol;
    }
    printf("Symbol inserted: %s\n", name);
}
Symbol* lookup(char *name) {
    int index = hash(name);
    Symbol *temp = hashTable[index];
    
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL) {
            Symbol *temp = hashTable[i];
            while (temp != NULL) {
                printf("Name: %s, Type: %s, Scope: %d\n", temp->name, temp->type, temp->scope);
                temp = temp->next;
            }
        }
    }
}

int main() {
    int choice;
    char name[50], type[20];
    int scope;
    Symbol *s;

    while(1) {
        printf("\nSymbol Table Operations\n");
        printf("1. Insert\n");
        printf("2. Lookup\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter symbol name: ");
                scanf("%s", name);
                printf("Enter symbol type: ");
                scanf("%s", type);
                printf("Enter symbol scope: ");
                scanf("%d", &scope);
                insert(name, type, scope);
                break;
            case 2:
                printf("Enter symbol name to lookup: ");
                scanf("%s", name);
                s = lookup(name);
                if (s != NULL) {
                    printf("Symbol found: Name: %s, Type: %s, Scope: %d\n", s->name, s->type, s->scope);
                } else {
                    printf("Symbol not found\n");
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
