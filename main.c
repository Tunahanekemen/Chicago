#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int roll_a_dice () { // Function of rolling a dice.
  int dice = rand() % 6 +1;
  return dice;
}

int calculate_score(int dice1, int dice2,int target) { //Function of calculate the score.
  if (dice1 + dice2 == target) {
    return target;
  }
  return 0;
}

int play_user(int a_round) { // Function of player round
  int total =0;
  int turn =1;
  char anw = 'N';
  printf("\nRound %d -- Your Turn: (Target = %d)\n",a_round,a_round+1);
  printf("==================================================\n");
   do {
    int score = 0;
    int dice1 = roll_a_dice();
    int dice2 = roll_a_dice();
    printf("you got > [Dice 1]: %d [Dice 2]: %d\n",dice1,dice2);
    score = calculate_score(dice1,dice2,a_round+1);
    total += score;
     if (anw == 'Y' &&  score == 0 ) { //if player loses after win , it gives 0 for player
       total =0;
     }
    printf("Your score: %d Total score: %d\n",score,total);
    if (turn <= 2) {
      printf("\nShall I roll for you again (Y/N)?");
      scanf("\n%c",&anw);
    }
    turn++;
  }while (anw == 'Y' && turn <= 3);
  return total;
}

int play_computer(int a_round) { // Function of computer round
  int total =0;
  int turn =1;
  int dice1,dice2;
  printf("\nRound %d -- My Turn: (Target = %d)\n",a_round,a_round+1);
  printf("==================================================\n");
  do {
    int score = 0;
    dice1 = roll_a_dice();
    dice2 = roll_a_dice();
    printf("I rolled them and I got > [Dice 1]: %d [Dice 2]: %d\n",dice1,dice2);
    score = calculate_score(dice1,dice2,a_round+1);
    total += score;
    printf("My score: %d Total score: %d\n",score,total);
    turn ++;
    if (turn <= 3 && dice1 + dice2 == a_round) { // if the sum of dice values is 1 less than the target , computer chooses to roll dices again
      printf("Rolled again!\n");
    }
  }while (turn <= 3 && dice1 + dice2 == a_round);
  return total;
}

void scoresheet(int player, int computer, int round) {
  printf("\nOur scoresheet after round %d:",round);
  printf("\n==================================================\n");
  printf("My score\tYour score\n");
  printf("%d\t\t%d\n",computer,player);
}

int main(void) {
  srand(time(NULL));
  int player_total = 0,computer_total =0;
  int round,computer_turn =0;
  printf("Welcome to Chicago game.\nLet's get started!\n\n");
  int dice1,dice2,sum_dice;
  do { /
    dice1 = roll_a_dice();
    dice2 = roll_a_dice();
    printf("I have rolled the dice and got %d and %d!\n",dice1,dice2);
    sum_dice = dice1 + dice2;
    dice1 = roll_a_dice();
    dice2 = roll_a_dice();
    printf("I have rolled the dice for you, and you got %d and %d!\n\n",dice1,dice2);
    if (sum_dice > dice1+dice2) {
      computer_turn = 1;
    } else if (sum_dice == dice1+dice2) {
      printf("Rolled again!\n"); //roll back
    }
  } while (sum_dice == dice1+dice2);
  do {
    printf("How many rounds would you like to play?");
    scanf("%d", &round);
    if (round <= 0 || round > 11) {
      printf("%d is an invalid number of rounds, maximum valid number of rounds is 11. Try Again.\n",round);
    }
  }while (round <= 0 || round > 11);
  for (int a_round=1; a_round <= round; a_round++) { // a_round = current round
    if (computer_turn == 1) {
      computer_total += play_computer(a_round);
      player_total += play_user(a_round);
    } else {
      player_total += play_user(a_round);
      computer_total += play_computer(a_round);
    }
    scoresheet(player_total,computer_total,a_round);
  }
  if (computer_total > player_total) { // Condition determines who wins
    printf("I AM THE WINNER!!\n");
  } else if (computer_total < player_total) {
    printf("YOU ARE THE WINNER!!\n");
  } else {
    printf("NO WINNER FOR THIS GAME!\n");
  }

}