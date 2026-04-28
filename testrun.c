#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number;
    int guess;
    int attempts;
    int maxAttempts=6;
    int choice;
    int score = 0;
    char replay;

    // USING srand(time(0)) TO FETCH THE CURRENT TIME SO THAT IT GENERATES A NEW SEED EVERYTIME AND
    // HENCE MAKING THE GAME UNPREDICTIBLE...
    srand(time(0));

    do
    {
        attempts = 0;

        printf("\n============================\n");
        printf("\n==== NUMBER GUESSING GAME ====\n");
        printf("\n==============================\n");

        //SELECT DIFFICULTY LEVEL OF GAME...
        printf("Choose Difficulty Level:\n");
        printf("1. Easy (1 - 50)\n");
        printf("2. Medium (1 - 100)\n");
        printf("3. Hard (1 - 250)\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            number = rand() % 50 + 1;
        else if (choice == 2)
            number = rand() % 100 + 1;
        else
            number = rand() % 250 + 1;

        printf("\nGuess the number!\n");
        printf("You have %d attempts \n", maxAttempts);

        // A HINT WILL BE GIVEN TO THE PLAYER THAT THE NUMBER T0 BE GUESSED IS
        // EVEN/ODD...

        if (number % 2 == 0)
        {
            printf("Hint: The number is EVEN\n");
        }
        else
        {
            printf("Hint: The number is ODD\n");
        }

        while (attempts < maxAttempts)
        {
            printf("\nEnter your guess: ");
            scanf("%d", &guess);

            // Input Validation
            if (guess < 1 || guess > 250)
            {
                printf("Invalid Input!!!\n");
                continue;
            }

            attempts++;

            int difference = abs(guess - number);

            if (guess == number)
            {
                printf("\n Correct! You guessed the number!\n");
                printf("Attempts used: %d\n", attempts);
                score++;
                printf("Score: %d\n", score);
                break;
            }
            else if (difference <= 2)
            {
                printf("Very Close!\n");
            }
            else if (difference <= 5)
            {
                printf("Close! Keep trying.\n");
            }
            else if (guess > number)
            {
                printf("Too High!\n");
            }
            else
            {
                printf("Too Low!\n");
            }

            printf("Attempts left: %d\n", maxAttempts - attempts);
        }

        if (guess != number)
        {
            printf("\nNice try! The correct number was %d\n", number);
            printf("Better luck next time!\n");
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &replay);

    } while (replay == 'y' || replay == 'Y');

    printf("\n Thanks for playing! \n Final Score: %d\n", score);

    return 0;
}