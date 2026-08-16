#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secretNumber;
    int guess;
    int attempts = 0;
    char playAgain;

    /* Initialize random number generator */
    srand((unsigned int)time(NULL));

    printf("\n========================================\n");
    printf("          NUMBER GUESSING GAME\n");
    printf("========================================\n");

    do
    {
        /* Generate a random number between 1 and 100 */
        secretNumber = rand() % 100 + 1;
        attempts = 0;

        printf("\nI have selected a number between 1 and 100.\n");
        printf("Try to guess the number!\n");

        while (1)
        {
            printf("\nEnter your guess: ");

            if (scanf("%d", &guess) != 1)
            {
                printf("Invalid input! Please enter a number.\n");

                /* Clear invalid input */
                while (getchar() != '\n')
                    ;

                continue;
            }

            if (guess < 1 || guess > 100)
            {
                printf("Please enter a number between 1 and 100.\n");
                continue;
            }

            attempts++;

            if (guess > secretNumber)
            {
                printf("Too high! Try a smaller number.\n");
            }
            else if (guess < secretNumber)
            {
                printf("Too low! Try a larger number.\n");
            }
            else
            {
                printf("\nCongratulations! You guessed the number!\n");
                printf("The number was: %d\n", secretNumber);
                printf("Number of attempts: %d\n", attempts);
                break;
            }
        }

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'Y' || playAgain == 'y');

    printf("\n========================================\n");
    printf("       Thanks for playing!\n");
    printf("========================================\n");

    return 0;
}