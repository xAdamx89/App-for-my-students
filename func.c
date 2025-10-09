#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "func.h"

void exitApp();
void choose(int a);
void openAndReadFile(char *tmpfptr, int ilePytan, int iloscPytanZPodrecznika);

void greetingScreean()
{
    printf("Welcome in app to conduct tests for students\n");
    printf("Please, choose topic to perform an exam:\n");

    printf("0 - Exit application\n");
    printf("1 - Kinematyka mechanizmów maszyn manipulacyjnych - 4 pytania\n");
    printf("2 - Przetworniki oraz sensoryka - 4 pytania\n");
    printf("3 - Zasady działania, budowa i zastosowanie sensorów - 4 pytania\n");
    printf("4 - Sensoryka robotów - 4 pytania\n");
    printf("5 - Maszyny manipulacyjne - 4 pytania\n");
    printf("6 - Bezpieczenstwo pracy z manipulatorami - 4 pytania\n");
    printf("7 - Projektowanie i realizacja elektrycznych układów sterowania w robotyce - 4 pytania\n");
    printf("------------------ 1g i 2g ------------------\n");
    printf("9 - kartkówka nr 1\n");
}

void exitApp()
{
    printf("Do zobaczenia!\n");
    exit(0);
}
void choose(int a)
{
    switch(a)
    {
        case 0: exitApp();
        case 1:
        {
            char file[] = "testy/Kinematyka mechanizmów maszyn manipulacyjnych.txt\0";
            char *fptr = file;
            openAndReadFile(fptr, 4, 9);
        }break;
        case 2:
        {
            char file[] = "testy/Przetworniki_sensoryka.txt\0";
            char *fptr = file;
            openAndReadFile(fptr, 4, 15);
        }break;
        case 3:
        {
            char file[] = "testy/Zasady działania, budowa i zastosowanie sensorów.txt\0";
            char *fptr = file;
            openAndReadFile(fptr, 4, 43);
        }break;
        case 4:
        {
            char file[] = "testy/Sensoryka robotów.txt\0";
            char *fptr = file;
            openAndReadFile(fptr, 4, 9);
        }break;
        case 5:
        {
            char file[] = "testy/Maszyny manipulacyjne.txt\0";
            char *fptr = file;
            openAndReadFile(fptr, 4, 20);
        }break;
        case 6:
        {
            char file[] = "testy/Bezpieczenstwo pracy z manipulatorami.txt\0";
            char *fptr = file;
            openAndReadFile(fptr, 4, 7);
        }break;
        case 7:
        {
            char file[] = "testy/Projektowanie i realizacja elektrycznych układów sterowania w robotyce.txt\0";
            char *fptr = file;
            openAndReadFile(fptr, 4, 25);
        }break;
        case 8:
        {
            char file[] = "testy/Technika regulacji.txt\0";
            char *fptr = file;
            openAndReadFile(fptr, 4, 11);
        }break;
        case 9:
        {
            char file[] = "testy/kart1-1g-2g.txt\0";
            char *fptr = file;
            openAndReadFile(fptr, 4, 4);
        }break;
    }
}
void openAndReadFile(char *tmpfptr, int ilePytan, int iloscPytanZPodrecznika)
{
    int buffor = 255;
    char fPath[buffor];
    int i = 0;

    while(*tmpfptr != '\0' && i < buffor)
    {
        fPath[i] = *tmpfptr;
        tmpfptr++;
        i++;
    }
    fPath[i] = '\0';

    //Debug czy wczytuje prawidłowy string z nazwą ścieżki testu
    //printf("%s\n", fPath);

    FILE *fptr;
    fptr = fopen(fPath, "r");

    if (fptr == NULL)
    {
        printf("Not able to open file. fptr == NULL\n");
        return;
    }

    //debug odczytu pierwszej linijki tekstu z pliku
    //char line[buffor];
    //fgets(line, sizeof(line), fptr);
    //printf("%s\n", line);

    int questionsNumber[4];

    srand(time(NULL));

    questionsNumber[0] = rand() % iloscPytanZPodrecznika + 1;

    do questionsNumber[1] = rand() % iloscPytanZPodrecznika + 1;
    while (questionsNumber[1] == questionsNumber[0]);

    do questionsNumber[2] = rand() % iloscPytanZPodrecznika + 1;
    while (questionsNumber[2] == questionsNumber[0] || questionsNumber[2] == questionsNumber[1]);

    do questionsNumber[3] = rand() % iloscPytanZPodrecznika + 1;
    while (questionsNumber[3] == questionsNumber[0] || questionsNumber[3] == questionsNumber[1] || questionsNumber[3] == questionsNumber[2]);

    //Debug losowanych numerów pytań
    //for(int i = 0; i < 4; i++) printf("%d ", questionsNumber[i]);
    //printf("\n");

    char line[buffor];
    while(fgets(line, sizeof(line), fptr))
    {
        //Debug odczytu wszystkich linii z pliku
        //printf("%s", line);
        //Debug poprawnego czytania numeru pytania    
        //printf("%c%c%c", line[0], line[1], line[2]);

        int nrPyt = atoi(line);

        //Debug prawidłowego odczytu nr pytania z linii za pomocą funkcji atoi()
        //printf("%d ", nrPyt);
        //printf("\n");


        if((nrPyt == questionsNumber[0] || nrPyt == questionsNumber[1] || nrPyt == questionsNumber[2] || nrPyt == questionsNumber[3])) 
        {
            printf("%s", line);
        }   
    }

    printf("\n\n\n");
    fclose(fptr);
}