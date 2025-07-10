#include <stdio.h>
#include <string.h>

#define Max_Students 1000
#define Max_files 3
#define MAX_LINE_LENGTH 1000

struct Student
{
	char Fname[15];
	char Lname[15];
	char Mcode[10];
	int Age;
	float grade;
	char sector[20];
};

void AddSTD();
void DelSTD();
void ModSTD();
void ClearList();
void Menu();

int main()
{
	struct Student newStudent[Max_Students];
	
	int i;
	
	const char *Filepath[Max_files] = {"/home/rayane/School/Common_Core","/home/rayane/School/1st_Bac","/home/rayane/School/2nd_Bac"};

	FILE *fptr;

	for (i = 0 ; i < Max_files ; i++)
	{
		fptr = fopen(Filepath[i] ,"a");
		if (fptr == NULL)
		{
			perror("Error Opening File");
			return 1;
		}
		fclose(fptr);
	}
	Menu();
	return 0;
}

void AddSTD()
{
	struct Student student;
	int lvl;

	printf("In which Level the student is in :\n1- Common Core\n2- 1st Bac\n3- 2nd Bac\n");
	scanf("%d", &lvl);
	getchar();

	FILE *fptr;

	if (lvl == 1)
	{
		fptr = fopen("/home/rayane/School/Common_Core" ,"a");

		printf("First Name : ");
		scanf(" %[^\n]", student.Fname);
        
		printf("Last Name : ");
		scanf(" %[^\n]", student.Lname);
		
		printf("Massar code : ");
		scanf("%s", student.Mcode);
        
		printf("Age : ");
		scanf("%d", &student.Age);
        
		printf("Past year grade : ");
		scanf("%f", &student.grade);
        
		printf("Enter the sector : ");
		scanf("%s", student.sector);
        
	
		fprintf(fptr, "First Name : %-30sLast Name : %-30sMassarCode : %-10.10s       Age : %-4d       Past year grade : %-2.2f       Sector : %-2s\n", student.Fname, student.Lname, student.Mcode, student.Age, student.grade, student.sector);

		fclose(fptr);
	}
	
	else if (lvl == 2)
		{
		fptr = fopen("/home/rayane/School/1st_Bac" ,"a");

		printf("First Name : ");
		scanf(" %[^\n]", student.Fname);
        getchar();
		printf("Last Name : ");
		scanf(" %[^\n]", student.Lname);
        getchar();
		printf("Massar code : ");
		scanf("%s", student.Mcode);
        getchar();
		printf("Age : ");
		scanf("%d", &student.Age);
        getchar();
		printf("Past year grade : ");
		scanf("%f", &student.grade);
        getchar();
		printf("Enter the sector : ");
		scanf("%s", student.sector);
        getchar();
	
		fprintf(fptr, "First Name : %-30sLast Name : %-30sMassarCode : %-10.10s       Age : %-4d       Past year grade : %-2.2f       Sector : %-2s\n", student.Fname, student.Lname, student.Mcode, student.Age, student.grade, student.sector);
		
		fclose(fptr);
		}
	else if (lvl == 3)
		{
		fptr = fopen("/home/rayane/School/2nd_Bac" ,"a");

		printf("First Name : ");
		scanf(" %[^\n]", student.Fname);
        getchar();
		printf("Last Name : ");
		scanf(" %[^\n]", student.Lname);
        getchar();
		printf("Massar code : ");
		scanf("%s", student.Mcode);
        getchar();
		printf("Age : ");
		scanf("%d", &student.Age);
        getchar();
		printf("Past year grade : ");
		scanf("%f", &student.grade);
        getchar();
		printf("Enter the sector : ");
		scanf("%s", student.sector);
        getchar();
	
		fprintf(fptr, "First Name : %-30sLast Name : %-30sMassarCode : %-10.10s       Age : %-4d       Past year grade : %-2.2f       Sector : %-2s\n", student.Fname, student.Lname, student.Mcode, student.Age, student.grade, student.sector);
		
		fclose(fptr);
		}
	else
		{
		printf("PLease enter a number between 1 and 3\n");
		}
}

void ModSTD()
{
    char D_Mcode[10]; // Massar code to modify the student
    int lvl;
    char Mod[1000]; // Variable to store the file content
    char filePath[100];

    printf("Massar code of the student : ");
    scanf("%10s", D_Mcode);
	while (getchar() != '\n'); 
    printf("In which level the student is in :\nCommon Core (1)\n1st Bac (2)\n2nd Bac (3)\n");
    scanf("%d", &lvl);

    switch (lvl) {
        case 1:
            strcpy(filePath, "/home/rayane/School/Common_Core");
            break;
        case 2:
            strcpy(filePath, "/home/rayane/School/1st_Bac");
            break;
        case 3:
            strcpy(filePath, "/home/rayane/School/2nd_Bac");
            break;
        default:
            printf("Invalid level.\n");
            return;
    }

    FILE *fptr = fopen(filePath, "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *tempFile = fopen("/home/rayane/School/temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(fptr);
        return;
    }

    int found = 0;

    while (fgets(Mod, sizeof(Mod), fptr) != NULL) {
        if (strstr(Mod, D_Mcode) != NULL) {
			
            found = 1;
            printf("Please enter the new information:\n");

			char NewFname[15];
            char NewLname[15];
			char NewCode[15];
            int NewAge;
            float NewGrade;
            char NewSector[20];

			getchar();
			printf("Massar Code : ");
            scanf("%s", NewCode);
			getchar();
            printf("Last Name : ");
            scanf(" %[^\n]", NewLname);  
			getchar();
			printf("First Name : ");
            scanf(" %[^\n]", NewFname);
			getchar();
            printf("Age : ");
            scanf("%d", &NewAge);
			getchar();
            printf("Grade : ");
            scanf("%f", &NewGrade);
			getchar();
            printf("Sector : ");
            scanf("%s", NewSector);  
			getchar();

            fprintf(tempFile, "First Name : %-30sLast Name : %-30sMassarCode : %-10.10s       Age : %-4d       Past year grade : %-2.2f       Sector : %-2s\n",
                    NewFname, NewLname, D_Mcode, NewAge, NewGrade, NewSector);
        } else {
            fputs(Mod, tempFile);
        }
    }

    fclose(fptr);
    fclose(tempFile);

    // Replace the original file with the modified temporary file
    if (found) {
        remove(filePath);  // Delete the original file
        rename("/home/rayane/School/temp.txt", filePath);  // Rename temp file to original
        printf("Record updated successfully.\n");
    } else {
        remove("/home/rayane/School/temp.txt");  // Clean up temp file if no record was modified
        printf("Massar code not found.\n");
    }
}

void DelSTD() 
{
    char Fname[50];
    char Lname[50];
    int lvl;
    char filepath[100];
    char line[MAX_LINE_LENGTH];

    printf("Enter the First Name of the student: ");
    scanf(" %[^\n]", Fname);

    printf("Enter the Last Name of the student: ");
    scanf(" %[^\n]", Lname);

    printf("In which level the student is in:\n1- Common Core\n2- 1st Bac\n3- 2nd Bac\n");
    scanf("%d", &lvl);

    switch (lvl) {
        case 1:
            strcpy(filepath, "/home/rayane/School/Common_Core");
            break;
        case 2:
            strcpy(filepath, "/home/rayane/School/1st_Bac");
            break;
        case 3:
            strcpy(filepath, "/home/rayane/School/2nd_Bac");
            break;
        default:
            printf("Please enter a valid number between 1 and 3\n");
            return;
    }

    FILE *fptr = fopen(filepath, "r");
    if (fptr == NULL) {
        perror("Error opening the file");
        return;
    }

    FILE *tempFile = fopen("/home/rayane/School/temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(fptr);
        return;
    }

    int found = 0;

    while (fgets(line, sizeof(line), fptr) != NULL) {
        if (strstr(line, Fname) != NULL && strstr(line, Lname) != NULL) {
            found = 1;
        } else {
            fputs(line, tempFile);
        }
    }

    fclose(fptr);
    fclose(tempFile);

    if (remove(filepath) != 0) {
        perror("Error deleting original file");
        return;
    }
    if (rename("/home/rayane/School/temp.txt", filepath) != 0) {
        perror("Error renaming temporary file");
        return;
    }

    if (found) {
        printf("Student removed successfully!\n");
    } else {
        printf("Student not found!\n");
    }
}

void ClearList()
{
	int clear, lvl;
	char filepath[100];
	
	printf("In which Level the student is in :\n1- Common Core\n2- 1st Bac\n3- 2nd Bac\n");
	scanf("%d", &lvl);
	
	printf("Clear The list ?\n- Enter (1)\n- Cancel (2)\n");
	scanf("%d", &clear);

	switch (lvl) 
	{
        case 1:
            strcpy(filepath, "/home/rayane/School/Common_Core");
            break;
        case 2:
            strcpy(filepath, "/home/rayane/School/1st_Bac");
            break;
        case 3:
            strcpy(filepath, "/home/rayane/School/2nd_Bac");
            break;
        default:
            printf("Invalid level.\n");
            return;
    }
	
	if (lvl == 1)
	{
		FILE *fptr = fopen(filepath, "w");
		fclose(fptr);

		printf("List cleared successfully\n");
	}
	else if (lvl == 2)
	{
		FILE *fptr = fopen(filepath, "w");
		fclose(fptr);

		printf("List cleared successfully\n");
	}
	else if (lvl == 3)
	{
		FILE *fptr = fopen(filepath, "w");
		fclose(fptr);

		printf("List cleared successfully\n");
	}
}

void Menu()
{
    int choice;
    while (1) {
        printf("Enter your choice:\n1. Add Student\n2. Modify Student\n3. Delete Student\n4. Exit\n");
        
        // Read input with fgets to avoid issues with the input buffer
        if (scanf("%d", &choice) != 1) {
            // Clear the invalid input
            while (getchar() != '\n');
            printf("Invalid input! Please enter a valid number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                AddSTD();
                break;
            case 2:
                ModSTD();
                break;
            case 3:
                DelSTD();
                break;
            case 4:
                printf("Exiting program...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

