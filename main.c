#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Zadeklarowanie wskaźnika na plik oraz otwarcie pliku w trybie read
    FILE *fptr;
    fptr = fopen("testy/Przzetworniki_sensoryka.txt", "r");

    //inicjalizacja funckji rand() do losowania liczby typu int
    srand(time(NULL));

    int num1, num2;
    num1 = rand() % 15 + 1;
    num2 = rand() % 15 + 1;

    //Sprawdzenie czy plik istnieje - jeżeli nie, zwraca tekst oraz kończy program
    if(fptr == NULL)
    {
        printf("Podany plik nie istnieje\n");
        return 0;
    }

    //Tablica char przechowująca poszczególną linijke z pliku
    char myString[200];

    //Odczyt z pliku wszystkich linijek po kolei
    while(fgets(myString, 200, fptr)) 
    {    
        if(myString[1] == '.') if(myString[0] == num1 || myString == num2) printf("%d\n", myString[0]);
        else if(myString[2] == '.') printf("%c%c\n", myString[0], myString[1]);
    }

    //zamknięcie pliku - zwolnienie pamięci oraz zakończenie programu
    fclose(fptr);
    return 0;
}