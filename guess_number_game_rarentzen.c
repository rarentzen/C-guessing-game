#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//declare procedures
int player_swap(int player_number);
int guess_checker(int player, int correct_number, char guess[]);

//BEGIN MAIN
int main() {
    
    int player_input;
    char player_guess[3];
    int player1_pass_counter = 3;
    int player2_pass_counter = 3;
    int player1_consecutive_pass = 0;
    int player2_consecutive_pass = 0;
    srand(time(NULL));
    int current_player = rand() %2 + 1;
    int number_to_guess = rand() %10 + 1;
	printf("***Guess the Number Game***\n Player *%d* will go first\n\n",current_player);
	int no_winner = 1;
    while(no_winner == 1) 
	{int turn = 1;
    while(turn == 1) {
    printf("Player number?: ");
    scanf("%d", &player_input);
        if (player_input != current_player) {  
            printf("Liar! It is not your turn!\n"); 
        }
        else {
            turn = 0;
        }
    }
    int no_pass = 1;
    while(no_pass == 1) {printf("Enter your guess or type PASS to pass: ");
    scanf("%s", player_guess);
	int status_check = guess_checker(current_player, number_to_guess, player_guess);
    if (status_check == 0) {
        no_pass = 0;
        no_winner = 0;
    }
	else if (status_check == 1) {
        if (current_player == 1 && player1_consecutive_pass == 0 && player1_pass_counter > 0) {
            --player1_pass_counter;
            ++player1_consecutive_pass;
            printf("Player 1 PASSES, they have passed * %d * time(s) and have * %d * pass(es) remaining.\n", 3-player1_pass_counter, player1_pass_counter);
            no_pass = 0; //break from pass loop
            current_player = player_swap(current_player);
        } else if (current_player == 1 && player1_consecutive_pass == 1) {
            printf("You passed on your last turn. You cannot pass twice in a row. Please enter guess..\n");
        }//condition 3 - INVALID pass - print invalid pass message and return to guess entry 
        else if (current_player == 1 && player1_pass_counter == 0) {
            printf("You are OUT of passes. Please enter guess..\n");
        }
		else if (current_player == 2 && player2_consecutive_pass == 0 && player2_pass_counter > 0) {
            --player2_pass_counter;
            ++player2_consecutive_pass;
            printf("Player 2 PASSES, they have passed * %d * time(s) and have * %d * pass(es) remaining.\n", 3-player2_pass_counter, player2_pass_counter);
            no_pass = 0; //break from pass loop
            current_player = player_swap(current_player);
        }
		else if (current_player == 2 && player2_consecutive_pass == 1) {
            printf("You passed on your last turn. You cannot pass twice in a row. Please enter guess..\n");
        }
		else if (current_player == 2 && player2_pass_counter == 0) {
            printf("You are OUT of passes. Please enter guess..\n");
        }
        
    }
	else if (status_check == 2) {
        
        if (current_player == 1 && player1_consecutive_pass > 0) {
            --player1_consecutive_pass;
        }
        if (current_player == 2 && player2_consecutive_pass > 0) {
            --player2_consecutive_pass;
        }
        no_pass = 0; //break from pass loop
        current_player = player_swap(current_player); //swap players turn
    }
   }
  }
    printf("GAME OVER");
}

int guess_checker(int player, int correct_number, char guess[]) {
    int guess_int = atoi(guess);
    if (guess_int == correct_number) {
        printf("Congratulations! Player %d WINS!\n" ,player);
        return 0;
    }
    else if (strcmp(guess, "PASS") == 0) {
        return 1;
    }
    else if (guess_int < correct_number) {
        printf("Too low, sorry..\n");
        return 2;
    }
    else if (guess_int > correct_number) {
        printf("Too high, sorry..\n");
        return 2;
    }
}

int player_swap(int player_number) {
    if (player_number == 1) {
        return 2;
    }
    return 1;
}//END FUNCTION player_swap

//END PROGRAM