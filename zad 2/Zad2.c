/*2. Definirati strukturu osoba (ime, prezime, godina rodenja) i napisati program koji:
A. dinamicki dodaje novi element na pocetak liste
B. ispisuje listu
C. dinamicki dodaje novi element na kraj liste
D. pronalazi element u listi (po porezimenu)
E. brise odredeni element iz liste
U zadatku se ne smiju koristiti globalne varijable. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


typedef struct person* position;

typedef struct person 
{
	char name[MAX];
	char surname[MAX];
	int yearob;

	position next;
} person;


position createPerson();

/* A) */ int addPerson(position Head);
/* B) */ int printList(position firstEl);
/* C) */ int addPersonToEnd(position Head);
/* D) */ void findPerson(position firstEl, char surn[MAX]);
/* E) */ void delPerson(position firstEl, char surn[MAX]);


int main() 
{
	person Head = { {0}, {0}, 0, NULL };


	addPerson(&Head);
	addPerson(&Head);

	if (addPerson) printf("\nNew person added!\n");
	else printf("\nError! Could not add a new person.\n");

	addPersonToEnd(&Head);

	if (addPersonToEnd) printf("\nNew person added!\n");
	else printf("\nError! Could not add a new person.\n");

	printList(Head.next);

	char surname[MAX] = { NULL };
	printf("Unesite prezime osobe koju tražite: ");
	scanf("%s", surname);
	//findPerson(Head.next, surname);

	delPerson(Head.next, surname);

	printList(Head.next);

	return 0;
}


position createPerson()
{
	position newPerson = NULL;

	newPerson = (position)malloc(sizeof(person));

	if (!newPerson) {
		printf("Memory allocation error!\n");
		return(-1);
	};

	newPerson->next = NULL;

	printf("New person:\nName? ");
	scanf("%s", newPerson->name);

	printf("Surame? ");
	scanf("%s", newPerson->surname);

	printf("Year of birth? ");
	scanf("%d", &newPerson->yearob);

	return newPerson;
}


/* A) */ 
int addPerson(position Head) 
{
	position newPerson = createPerson();

	newPerson->next = Head->next;
	Head->next = newPerson;

	return 1;
}


/* B) */
int printList(position firstEl) 
{
	position current = firstEl;

	printf("\nList:\n");

	if (current)
		for (int i = 1; current != NULL; current = current->next)
		{
			printf("%d. person: %s %s, born: %d\n", i, current->name, current->surname, current->yearob);
			i++;
		}
	else
		printf("List is empty!");

	return 1;
}


/* C) */ 
int addPersonToEnd(position Head) 
{
	position newPerson = createPerson();

	position current = Head->next;

	for (; current->next != NULL; current = current->next);
	
	current->next = newPerson;

	return 1;
}


/* D) */ 
void findPerson(position firstEl, char surn[MAX])
{
	position current = firstEl;

	for (int i = 1; current != NULL; current = current->next)
	{
		if (!strcmp(current->surname, surn))
			printf("%d. person: %s %s, born: %d\n", i, current->name, current->surname, current->yearob);
		i++;
	}
}


/* E) */ 
void delPerson(position firstEl, char surn[MAX])
{
	position current = firstEl;
	if (current)
	{
		for (; current != NULL; current = current->next)
		{
			if (!strcmp(current->next->surname, surn)) current->next = current->next->next;

		}
	}
	else printf("List is empty!");
}
