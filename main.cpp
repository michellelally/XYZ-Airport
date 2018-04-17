#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int passportNo;
    char firstname[20];
    char surname[20];
    int yearBorn;
    char email[30];
    int country;
    int travelClasss;
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

void addElementAtStart(struct node **top, int passNo);

void addElementAtEnd(struct node *top, int passNo);

void deleteElementAtEnd(struct node *top);

void deleteElementAtStart(struct node **top);

void deleteElementAtPos(struct node *top, int position);

void displayList(struct node *top);

void displayElementInList(struct node *top, int passNo);

int searchList(struct node *top, int passNo);

int length(struct node *top);

void generateStatistics(struct node *top);

void generateStatisticsTravelClass(struct node *top);

void generateStatisticsYearBorn(struct node *top);


void main() {
    struct node* headPtr = NULL;
    int option, temp, passNo, found, pos, stat;
    printf("1. Add a new passenger\n");
    printf("2. Display all passengers to screen\n");
    printf("3. Display passengers details\n");
    printf("4. Update a passengers statistics\n");
    printf("5. Delete passengers\n");
    printf("6. Generate statistics\n");
    printf("7. Print all player details to a report file\n");
    printf("8. List all the passenger of the following the UK in order of year born.\n");
    printf("Please enter -1 to exit\n");
    printf("Enter option > ");
    scanf_s("%d", &option);

    while (option != -1) {
        switch (option){
            case 1:
                printf("Add a new passenger\n");
                printf("Please enter the passport number for this passenger (Note: It must be unique) > \n");
                scanf("%d", &passNo);
                if (headPtr == NULL) {
                    addElementAtStart(&headPtr, passNo);
                }
                else {
                    found = searchList(headPtr, passNo);
                    if (found != 1){
                        addElementAtEnd(headPtr, passNo);
                    }
                    else {
                        printf("The passport number is not unique.");
                    }
                }
                break;
            case 2:
                printf("Display all passengers to screen\n");
                displayList(headPtr);
                break;
            case 3:
                printf("Display passengers details\n");
                printf("Please enter the passport number for the passenger you want to display (Note: It must be unique) > \n");
                scanf("%d", &passNo);
                if (headPtr == NULL) {
                    printf("The database is empty.");
                }
                else {
                    found = searchList(headPtr, passNo);
                    if (found == 1){
                        displayElementInList(headPtr, passNo);
                    }
                    else {
                        printf("The passport number is not in the list.");
                    }
                }
                break;
            case 4:
                printf("4. Update passengers Statistics\n");
                break;
            case 5:
                printf("Delete passengers\n");
                if (length(headPtr) == 0){
                    printf("The database is empty.");
                }
                else if (length(headPtr) == 1){
                    printf("deleteElementAtStart");
                    deleteElementAtStart(&headPtr);
                }
                else {
                    printf("Please enter the number for the passenger you want to delete > \n");
                    scanf("%d", &pos);
                    deleteElementAtPos(headPtr, pos);
                }
                break;
            case 6:
                generateStatisticsYearBorn(headPtr);
                break;
            case 7:
                printf("7. Print all player details to a report file\n");
                break;
            case 8:
                printf("8. List all the passenger of the following the UK in order of year born.\n");
                break;
        }

        printf("\n");
        printf("1. Add a new passenger\n");
        printf("2. Display all passengers to screen\n");
        printf("3. Display passengers details\n");
        printf("4. Update passengers Statistics\n");
        printf("5. Delete passengers\n");
        printf("6. Generate statistics\n");
        printf("7. Print all player details to a report file\n");
        printf("8. List all the passenger of the following the UK in order of year born.\n");
        printf("Please enter -1 to exit\n");
        printf("Enter option > ");
        scanf_s("%d", &option);
    }
}

void addElementAtStart(struct node **top, int passNo){
    struct node* newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    newNode->passengers.passportNo = passNo;

    printf("Please enter the following information:\n");
    printf("First Name > \n");
    scanf("%s", newNode->passengers.firstname);
    printf("Surname > \n");
    scanf("%s", newNode->passengers.surname);
    printf("Year Born > \n");
    scanf("%d", &newNode->passengers.yearBorn);
    printf("Email Address > \n");
    scanf("%s", newNode->passengers.email);
    printf("Which of the following areas did you travel from: \n");
    printf("\t1. UK \n \t2. Rest of Europe \n \t3. Asia \n \t4. Americas \n \t5. Australasia \n");
    scanf("%d", &newNode->passengers.country);
    printf("What travel class did you use to travel to Ireland? \n");
    printf("\t1. Economy \n \t2. Premium Economy \n \t3. Business Class \n \t4. First Class \n");
    scanf("%d", &newNode->passengers.travelClasss);
    printf("How many trips to Ireland do you make per year? \n");
    printf("\t1. Less than three times per year \n \t2. Less than five times per year \n \t3. More than five times per year \n");
    scanf("%d", &newNode->passengers.trips);
    printf("On average how long is your duration? \n");
    printf("\t1. One day \n \t2. Less than 3 days \n \t3. Less than 7 days \n \t4. More than 7 days  \n");
    scanf("%d", &newNode->passengers.duration);

    newNode->NEXT = *top;
    *top = newNode;
}

void addElementAtEnd(struct node *top, int passNo){
    struct node* temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp = top;

    while (temp->NEXT != NULL) {
        temp = temp->NEXT;
    }

    struct node* newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    newNode->passengers.passportNo = passNo;

    char trip[4][35] = {"", "Less than three times per year", "Less than five times per year", "More than five times per year"};

    printf("Please enter the following information:\n");
    printf("First Name > \n");
    scanf("%s", newNode->passengers.firstname);
    printf("Surname > \n");
    scanf("%s", newNode->passengers.surname);
    printf("Year Born > \n");
    scanf("%d", &newNode->passengers.yearBorn);
    printf("Email Address > \n");
    scanf("%s", newNode->passengers.email);
    printf("Which of the following areas did you travel from? \n");
    printf("\t1. UK \n \t2. Rest of Europe \n \t3. Asia \n \t4. Americas \n \t5. Australasia \n");
    scanf("%d", &newNode->passengers.country);
    printf("What travel class did you use to travel to Ireland? \n");
    printf("\t1. Economy \n \t2. Premium Economy \n \t3. Business Class \n \t4. First Class \n");
    scanf("%d", &newNode->passengers.travelClasss);
    printf("How many trips to Ireland do you make per year? \n");
    printf("\t1. Less than three times per year \n \t2. Less than five times per year \n \t3. More than five times per year \n");
    scanf("%d", &newNode->passengers.trips);
    printf("On average how long is your duration? \n");
    printf("\t1. One day \n \t2. Less than 3 days \n \t3. Less than 7 days \n \t4. More than 7 days  \n");
    scanf("%d", &newNode->passengers.duration);


    newNode->NEXT = NULL;
    temp->NEXT = newNode;
}

int searchList(struct node *top, int passNo) {
    struct node *temp;
    int found = 0;
    temp = top;
    while (temp != NULL) {
        if (temp->passengers.passportNo == passNo) {
            found = 1;
        }
        temp = temp->NEXT;
    }
    return found;
}

void displayList(struct node *top){
    char country[6][15] = {"", "UK", "Rest of Europe", "Asia", "Americas", "Australasia"};
    char classes[5][20] = {"", "Economy", "Premium Economy", "Business Class", "First Class"};
    char trip[4][35] = {"", "Less than three times per year", "Less than five times per year", "More than five times per year"};
    char duration[5][20] = {"", "One day", "Less than 3 days", "Less than 7 days", "More than 7 days"};
    int counter = 1;

    struct node* temp;
    temp = top;

    while (temp != NULL){
        printf("\nPassenger %d\n\n", counter);
        printf("Passport Number > %d \n", temp->passengers.passportNo);
        printf("First Name > %s \n", temp->passengers.firstname);
        printf("Surname > %s \n", temp->passengers.surname);
        printf("Year Born > %d \n", temp->passengers.yearBorn);
        printf("Email Address > %s \n", temp->passengers.email);
        printf("Area traveled from > %s \n", country[temp->passengers.country]);
        printf("Travel class > %s \n", classes[temp->passengers.travelClasss]);
        printf("Trips > %s \n", trip[temp->passengers.trips]);
        printf("Duration > %s \n\n", duration[temp->passengers.duration]);

        counter++;
        temp = temp->NEXT;
    }
}

void displayElementInList(struct node *top, int passNo){
    char country[6][15] = {"", "UK", "Rest of Europe", "Asia", "Americas", "Australasia"};
    char classes[5][20] = {"", "Economy", "Premium Economy", "Business Class", "First Class"};
    char trip[4][35] = {"", "Less than three times per year", "Less than five times per year", "More than five times per year"};
    char duration[5][20] = {"", "One day", "Less than 3 days", "Less than 7 days", "More than 7 days"};

    struct node* temp;
    temp = top;

    while (temp != NULL){
        if (temp->passengers.passportNo == passNo) {
            printf("\n\n");
            printf("Passport Number > %d \n", temp->passengers.passportNo);
            printf("First Name > %s \n", temp->passengers.firstname);
            printf("Surname > %s \n", temp->passengers.surname);
            printf("Year Born > %d \n", temp->passengers.yearBorn);
            printf("Email Address > %s \n", temp->passengers.email);
            printf("Area traveled from > %s \n", country[temp->passengers.country]);
            printf("Travel class > %s \n", classes[temp->passengers.travelClasss]);
            printf("Trips > %s \n", trip[temp->passengers.trips]);
            printf("Duration > %s \n\n", duration[temp->passengers.duration]);
        }
        temp = temp->NEXT;
    }
}


void deleteElementAtStart(struct node **top){
    struct node* temp;
    temp = *top;
    *top = temp->NEXT;

    free(temp);
}

void deleteElementAtEnd(struct node *top){
    struct node* curr;
    struct node* prev_curr;

    curr = top;

    while (curr->NEXT != NULL)
    {
        prev_curr = curr;
        curr = curr->NEXT;
    }

    prev_curr->NEXT = NULL;
    free(curr);
}

void deleteElementAtPos(struct node *top, int position){
    struct node* temp;
    struct node* prev;
    int i;

    temp = (struct node *) malloc(sizeof(struct node));
    prev = (struct node *) malloc(sizeof(struct node));
    temp = top;

    for (i = 0;i < position - 1;i++)
    {
        if (i == (position-1)){
            break;
        }
        prev = temp;
        temp = temp->NEXT;
    }

    prev->NEXT = temp->NEXT;
    free(temp);
    printf("\nPassenger has been deleted.\n");
}

int length(struct node *top){
	struct node* curr;
	int len = 0;
	curr = top;

	while (curr != NULL)
	{
		len++;
		curr = curr->NEXT;
	}
	return len;
}



void generateStatisticsYearBorn(struct node *top) {
    int country[5] = {0, 0, 0, 0, 0};
    int duration[4] = {0, 0, 0, 0};
    int total = 0;

    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp = top;

    while (temp != NULL) {
        if (temp->passengers.yearBorn < 1980) {
            switch (temp->passengers.country) {
                case 1:
                    country[0]++;
                    total++;
                    break;
                case 2:
                    country[1]++;
                    total++;
                    break;
                case 3:
                    country[2]++;
                    total++;
                    break;
                case 4:
                    country[3]++;
                    total++;
                    break;
                case 5:
                    country[4]++;
                    total++;
                    break;
                default:
                    printf("Invalid input.");
                    break;
            }
            switch (temp->passengers.duration) {
                case 1:
                    duration[0]++;
                    break;
                case 2:
                    duration[1]++;
                    break;
                case 3:
                    duration[2]++;
                    break;
                case 4:
                    duration[3]++;
                    break;
                default:
                    printf("Invalid input.");
                    break;
            }
        }
        temp = temp->NEXT;
    }

    printf("Percentage of passengers who travel from The UK: %d \n", (country[0] * 100 / total));
    printf("Percentage of passengers who travel from The Rest of Europe: %d \n", (country[1] * 100 / total));
    printf("Percentage of passengers who travel from Asia: %d \n", (country[2] * 100 / total));
    printf("Percentage of passengers who travel from the Americas: %d \n", (country[3] * 100 / total));
    printf("Percentage of passengers who travel from Australasia: %d \n", (country[4] * 100 / total));
    printf("Percentage of passengers who spent one day in Ireland: %d \n", (duration[0] * 100 / total));
    printf("Percentage of passengers who spent less than 3 days in Ireland: %d \n", (duration[1] * 100 / total));
    printf("Percentage of passengers who spent less than 7 days in Ireland: %d \n", (duration[2] * 100 / total));
    printf("Percentage of passengers who spent more than 7 days in Ireland: %d \n", (duration[3] * 100 / total));

/*
    for (int i = 0; i < 5; i++){
       printf("country %d : %d \n", i, country[i]) ;
    }
    for (int i = 0; i < 4; i++){
        printf("duration  %d : %d  \n", i, duration[i]);
    }
*/

}






