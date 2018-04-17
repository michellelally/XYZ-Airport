#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int passportNo[20];
    char firstname[20];
    char surname[20];
    int yearBorn;
    char email[30];
    char country[20];
    char travelClass[20];
    int trips;
    int duration;
    struct node *NEXT;
} passenger;

struct node {
    passenger passengers;
    struct node* NEXT;
};

typedef struct {
    char username[6];
    char password[6];
} user;


void menu();

void addPassenger();

void addElementAtStart(struct node **top);

void addElementAtEnd(struct node *top);

void addElementAtPos(struct node *top, int position);

void deleteElementAtEnd(struct node *top);

void deleteElementAtStart(struct node **top);

void deleteElementAtPos(struct node *top, int position);

void displayList(struct node *top);

int searchList(struct node *top);

int length(struct node *top);

void main() {
    int option;
    printf("1. Add a new passenger\n");
    printf("2. Display all passengers to screen\n");
    printf("3. Display passengers details\n");
    printf("4. Update passengers Statistics\n");
    printf("5. Delete passengers\n");
    printf("6. Generate statistics\n");
    printf("7. Print all player details to a report file\n");
    printf("7. Print all player details to a report file\n");
    printf("Please enter -1 to exit\n");
    printf("Enter option: ");
    scanf_s("%d", &option);
    while (option != -1) {
        switch (option){
            case 1:
                printf("1. Add a new passenger\n");
                break;
            case 2:
                printf("2. Display all passengers to screen\n");
break;

        }
    }
}
