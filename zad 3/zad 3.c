/*2. Definirati strukturu osoba (ime, prezime, godina rodenja) i napisati program koji:
A. dinamicki dodaje novi element na pocetak liste
B. ispisuje listu
C. dinamicki dodaje novi element na kraj liste
D. pronalazi element u listi (po porezimenu)
E. brise odredeni element iz liste
U zadatku se ne smiju koristiti globalne varijable. */

/*3. Prethodnom zadatku dodati funkcije:
A. dinamički dodaje novi element iza određenog elementa,
B. dinamički dodaje novi element ispred određenog elementa,
C. sortira listu po prezimenima osoba (!!NAPRAVIT SORTIRANI UNOS!!),
D. upisuje listu u datoteku,
E. čita listu iz datoteke.*/


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

/* 2. */
/* A) */ int addPerson(position Head);
/* B) */ int printList(position firstEl);
/* C) */ int addPersonToEnd(position Head);
/* D) */ void findPerson(position firstEl, char surn[MAX]);
/* E) */ void delPerson(position firstEl, char surn[MAX]);

/* 3. */
/* A) */ int addBehind(position firstEl, char surn[MAX]);
/* B) */ int addBefore(position firstEl, char surn[MAX]);
/* C) */ int sortedInput(position Head);
/* D) */ int inFile(position Head);
/* E) */ int outOfFile(position Head);


int main()
{
	person Head = { {0}, {0}, 0, NULL };

	
	//addPerson(&Head);


	//addPersonToEnd(&Head);


	//printList(Head.next);

	/*
	char surname[MAX] = { NULL };
	printf("\nEnter surname of the person you're looking for: \n");
	scanf("%s", surname); */

	//addBehind(Head.next, surname);
	//addBefore(Head.next, surname);

	//findPerson(Head.next, surname);

	//delPerson(Head.next, surname);

	/*
	sortedInput(&Head);
	sortedInput(&Head);
	sortedInput(&Head);
	*/
	
	//inFile(&Head);
	outOfFile(&Head);

	printList(Head.next);

	return 0;
}


position createPerson()
{
	position newPerson = NULL;

	newPerson = (position)malloc(sizeof(person));

	newPerson->next = NULL;

	printf("New person:\nName? ");
	scanf("%s", newPerson->name);

	printf("Surame? ");
	scanf("%s", newPerson->surname);

	printf("Year of birth? ");
	scanf("%d", &newPerson->yearob);

	if (!newPerson) 
	{
		printf("Memory allocation error! Could not add a new person.\n");
		return(-1);
	}
	else
	{
		printf("\nNew person added!\n\n");
		return newPerson;
	}
}


/* 2. */

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


/* 3. */

/* A) */ 
int addBehind(position firstEl, char surn[MAX])
{
	position newPerson = createPerson();

	position current = firstEl;
	if (current)
	{
		for (; current != NULL; current = current->next)
		{
			if (!strcmp(current->surname, surn)) 
			{
				newPerson->next = current->next;
				current->next = newPerson;
			}
		}
	}

	return 1;
}


/* B) */ 
int addBefore(position firstEl, char surn[MAX]) 
{
	position newPerson = createPerson();

	position current = firstEl;
	if (current)
	{
		for (; current != NULL; current = current->next)
		{
			if (!strcmp(current->next->surname, surn))
			{
				newPerson->next = current->next;
				current->next = newPerson;
				break;
			}
		}
	}
	return 1;
}


/* C) */ 
int sortedInput(position head)
{
	position newPerson = createPerson();

	position current = head;

	while( current->next != NULL && strcmp(newPerson->surname, current->next->surname) > 0)
	{
		current = current->next;
	}

	newPerson->next = current->next;
	current->next = newPerson;

	return 1;
}


/* D) */ 
int inFile(position Head) 
{
	FILE* file;
	file = fopen("people.txt", "w");

	position current = Head->next;

	for (; current != NULL; current = current->next)
	{
		fprintf(file, "%s\t %s\t %d\n", current->name, current->surname, current->yearob);
	}

	fclose(file);

	return 1;
}


/* E) */ 
int outOfFile(position Head)
{
	FILE* file;
	file = fopen("people.txt", "r");

	position current = Head;

	for (; !feof(file); current = current->next)
	{
		position newPerson = NULL;

		newPerson = (position)malloc(sizeof(person));

		fscanf(file, "%s %s %d\n", newPerson->name, newPerson->surname, &newPerson->yearob);

		newPerson->next = current->next;
		current->next = newPerson;
	}

	fclose(file);

	return 1;
}