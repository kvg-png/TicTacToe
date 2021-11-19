#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];  /* the tic tac toe matrix */

char check(void);
char b;
void init_matrix(void);
void get_player1_move(void);
void get_player2_move(void);

void disp_matrix(void);

int main(void)
{
  char done;

  printf("Output Play (y/n):\n");
  scanf("%c", &b);
  printf("You entered %c.\n", b);

  printf("Starting game with 3 x 3 board.\n");
  printf("Each player should enter\na row and col num (eg: 2 0).\n");
  done =  ' ';
  init_matrix();

  do {
    printf("Player 1:\n");
    get_player1_move();
    done = check(); 
    if(done!= ' ') break; 
    printf("Player 2:\n");
    get_player2_move();
    done = check();
  } while(done== ' ');

  if(done=='X') printf("Player 2 is the winner.\n");
  else printf("Player 1 is the winner.\n");
  disp_matrix(); /* show final positions */

  return 0;
}

/* Initialize the matrix. */
void init_matrix(void)
{
  int i, j;

  for(i=0; i<3; i++)
    for(j=0; j<3; j++) matrix[i][j] =  ' ';
}

/* Get a player's move. */
void get_player1_move(void)
{
  int x, y;

  scanf("%d%*c%d", &x, &y);

  
  printf("Player 1 entered %d %d.\n", x, y);
  

  if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n");
    get_player1_move();
  }
  else matrix[x][y] = 'O';

  if (b == 'y'){
    disp_matrix();
  }

}

void get_player2_move(void)
{
  int x, y;

  scanf("%d%*c%d", &x, &y);

 
  printf("Player 2 entered %d %d.\n", x, y);
 

  if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n");
    get_player2_move();
  }
  else matrix[x][y] = 'X';

  if (b == 'y'){
    disp_matrix();
  }
}


/* Display the matrix on the screen. */
void disp_matrix(void)
{
  int t;
  printf("-------------\n");
  for(t=0; t<3; t++) {
    printf("| %c | %c | %c |",matrix[t][0],
            matrix[t][1], matrix [t][2]);
    printf("\n-------------\n");
  }

}

/* See if there is a winner. */
char check(void)
{
  int i;

  for(i=0; i<3; i++)  /* check rows */
    if(matrix[i][0]==matrix[i][1] &&
       matrix[i][0]==matrix[i][2]) return matrix[i][0];

  for(i=0; i<3; i++)  /* check columns */
    if(matrix[0][i]==matrix[1][i] &&
       matrix[0][i]==matrix[2][i]) return matrix[0][i];

  /* test diagonals */
  if(matrix[0][0]==matrix[1][1] &&
     matrix[1][1]==matrix[2][2])
       return matrix[0][0];

  if(matrix[0][2]==matrix[1][1] &&
     matrix[1][1]==matrix[2][0])
       return matrix[0][2];

  return ' ';
}