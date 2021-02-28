#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    srand(time(NULL));  //Srand takes seed as an input and is defined inside stlib.h
    return rand() % n;
}

int greater(char char1, char char2)
{
    //For rock paper scissors - Return 1 if char1>char2 and 0 otherwise. if char1==char2 it will return -1
    if (char1 == char2)
    {
        return -1;
    }
    else if (char1 == 'r' && char2 == 's')
    {
        return 1;
    }
    else if (char2 == 'r' && char1 == 's')
    {
        return 0;
    }
    else if (char1 == 'p' && char2 == 'r')
    {
        return 1;
    }
    else if (char2 == 'p' && char1 == 'r')
    {
        return 0;
    }

    else if (char1 == 's' && char2 == 'p')
    {
        return 1;
    }
    else if (char2 == 's' && char1 == 'p')
    {
        return 0;
    }
}

int main()
{
    int yourscore = 0, computerscore = 0, temp;
    char yourchar, computerchar;
    char dict[] = {'R', 'P', 'S'};
    printf("\n===============================================================================================================================\n\n");
    printf("\n\n\tWELCOME TO THE ROCK, PAPER & SCISSORS GAME\n");
    printf("\t==========================================\n\n");
    printf("\t..................Mr. X...................\n\n");
    printf("\t==========================================\n\n");


    for (int i = 0; i < 3; i++)
    {
        // YOUR INPUT
        printf("\tCHOOSE 1 FOR ROCK, 2 FOR PAPER & 3 FOR SCISSORS\n\n");
        printf("\tYOUR TURN: ");
        scanf("%d", &temp);
        getchar();
        yourchar = dict[temp - 1];
        printf(" -----------------\n");
        printf("| YOU CHOOSE: %c   |\n", yourchar);
        printf(" -----------------\n\n");

        //COMPUTER GENERATE
        printf("CHOOSE 1 FOR ROCK, 2 FOR PAPER & 3 FOR SCISSORS\n\n");
        printf("\tCOMPUTER'S TURN\n");
        temp = generateRandomNumber(3) + 1;
        computerchar = dict[temp - 1];
        printf(" --------------------\n");
        printf("| COMPUTER CHOOSE: %c |\n", computerchar);
        printf(" --------------------\n\n");

        
        if (greater(computerchar, yourchar) == 1)
        {
            computerscore++;
            printf("\t\tCOMPUTER GOT IT!\n\n");
        }
        else if (greater(computerchar, yourchar) == -1)
        {
            computerscore++;
            yourscore++;
            printf("\t\tIT'S A DRAW MATCH. BOTH ARE GOTH 1 POINT!\n\n");
        }
        else
        {
            yourscore++;
            printf("\t\tYOU GOT IT!\n\n");
        }

        printf(" =================\n");
        printf(" || YOU: %d      ||\n", yourscore);
        printf(" || COMPUTER: %d ||\n", computerscore);
        printf(" =================\n\n");

        printf("===========================================================\n\n");
    }

    printf(" ==========================\n");
    printf("||      FINAL SCORE        ||\n");
    printf("|-------------------------- |\n");
    printf("||    YOU     |  COMPUTER  ||\n");
    printf("||------------|------------||\n");
    printf("||     %d      |     %d      ||\n", yourscore, computerscore);
    printf(" ==========================\n\n");

    // COMPARE SCORE
    if (yourscore > computerscore)
    {
        printf("\n\t ==================================\n");
        printf("\t || .....YOU ARE THE WINNER..... ||\n");
        printf("\t ==================================\n");
    }
    else if (yourscore < computerscore)
    {
        printf("\n\t ------------------------\n");
        printf("\t| YOU LOOSE THE GAME |\n");
        printf("\t ------------------------\n");
    }
    else
    {
        printf("\n\t --------\n");
        printf("\t|| DRAW ||\n");
        printf("\t --------\n");
    }

    return 0;
}