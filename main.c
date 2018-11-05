/*
 * This program was made to sell tickets using files, but it all went horribly wrong and I swear I did my best
 *
 * Mario Emilio Aguilar Chung
 * A01411210@itesm.mx
 * 11/5/2018
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
//I establish the data structure for the client
struct client
{
    char name [100];
    char paymentMethod [50];
    double ticketPrice;
    bool free;
} clientInput[400][200];
//Prints the main menu
void mainMenu ()
{
    printf ("Welcome to the greatest rock show ever to grace the face of this planet \n");
    printf ("A. Buy a ticket \n");
    printf ("B. Save data \n");
    printf ("C. Show reports \n");
    printf ("D. Exit \n");
}

int main(void) {
    FILE *f1;
    char option;
    int zone;
    int row;
    int seat;
    f1 = fopen ("ticketInfo.txt", "rb");
//Prints the main menu and does the switches until the user asks to exit
    do
    {
        mainMenu ();
        scanf ("%c", &option);
        option = toupper (option);

        switch (option)
        {
            case 'A':
            {
                //Prints the available zones and their prices
                printf ("The available zones are the following: \n");
                printf ("1. VIP ($100 USD) \n");
                printf ("2. Platinum ($85 USD) \n");
                printf ("3. Gold ($70 USD) \n");
                printf ("4. Silver ($55 USD) \n");
                printf ("5. Green ($45 USD) \n");
                printf ("6. Yellow ($40 USD) \n");
                printf ("7. Red ($30 USD) \n");
                printf ("8. Sky Blue ($50 USD) \n");
                printf ("9. Navy Blue ($35 USD) \n");
                printf ("10. Deep Blue ($20 USD) \n");
                printf ("0. Return to main menu \n");
                scanf ("%i", &zone);
                switch (zone)
                {//If the user chooses to go for the VIP zone
                    case 1:
                    {
                        printf ("Choose a row between 1 and 5: \n");
                        scanf ("%i ", &row);
                        getchar();

                        printf ("Choose a seat between 51 and 150: \n");
                        scanf ("%i ", &seat);
                        getchar ();

                        clientInput[row][seat].ticketPrice = 100;

                        if (clientInput[row][seat].free = true)
                        {
                            getchar();
                            printf ("What is your name? \n");
                            fgets (clientInput[row][seat].name, sizeof(clientInput[row][seat].name), stdin);
                        }

                        else
                        {
                            printf ("Sorry, this seat has already been taken by %s\n", clientInput[row][seat].name);
                        }
                    }

                }

            }//The information is saved on a file
            case 'B':
            {
                f1 = fopen ("ticketInfo.txt", "wb");
                for (int i = 0; i < 400; i++)
                {
                    for (int j = 0; j < 200; j++)
                    {
                        if (clientInput[i][j].free = false)
                        {
                            fputs (clientInput[i][j].name, f1);
                            fputs (clientInput[i][j].paymentMethod, f1);
                            fputs (clientInput[i][j].ticketPrice, f1);
                        }
                    }
                }
            }
            default:
            {
                printf ("Invalid input\n");
            }

        }
//The information is once again saved in a file
    } while (option != 'D');
    f1 = fopen ("ticketInfo.txt", "wb");
    for (int i = 0; i < 400; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            if (clientInput[i][j].free = false)
            {
                fputs (clientInput[i][j].name, f1);
                fputs (clientInput[i][j].paymentMethod, f1);
                fputs (clientInput[i][j].ticketPrice, f1);
            }
        }
    }


    return 0;
}