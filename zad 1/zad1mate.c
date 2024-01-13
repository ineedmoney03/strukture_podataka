#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define MAXP 200


typedef struct  {
	char name[MAX];
	char surname[MAX];
	int points;
}student;

int countStudents();
int getStudInfo(student* student_array);
int printStudents(student* student_array, int numberOfS);

int main(){

	int numOfStud = countStudents();

	student* students;
	students = malloc(sizeof(student) * numOfStud);

	getStudInfo(students);

	printStudents(students, numOfStud);

	return 0;
}

int countStudents() {

	FILE* file;
	file = fopen("studenti.txt", "r");

	int stud_counter = 0;
	char buffer[MAX] = { 0 };

	if (file == NULL) {
		printf("File not open.");
		return(-1);
	}
	else
		while (!feof(file)) {
			fgets(buffer, MAX, file);
			stud_counter++;
		}

	fclose(file);

	return stud_counter;
}

int getStudInfo(student* student_array) {
	FILE* file;
	file = fopen("studenti.txt", "r");

	int i = 0;

	while (!feof(file)) {
		fscanf(file, "%s %s %d", student_array[i].name, student_array[i].surname, &student_array[i].points);
		i++;
	}

	fclose(file);

	return 0;
}

int printStudents(student* student_array, int numberOfS) {
	double relative;
	for (int i = 0; i < numberOfS; i++) {
		relative = ((double)student_array[i].points / MAXP) * 100;
		printf("%s %s %d %.2lf\n", student_array[i].name, student_array[i].surname, student_array[i].points, relative);
	}

	return 0;
}