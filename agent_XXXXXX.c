#include <stdlib.h>
#include "c4.h"
double agent_XXXXXX(Game_state *current_state, int player, int x, int y);
double super_cool_Xheuristic_a(Game_state *current_state, int player, int x, int y);
double super_cool_Xheuristic_b(Game_state *current_state, int player, int x, int y);
int getMaxBoard(Game_state *current_state);

double agent_XXXXXX(Game_state *current_state, int player, int x, int y)
{
   double score = 0;
   int is_game_won = game_won(current_state);

   if (is_game_won == player)
      score = 1;
   else if (is_game_won == other(player))
      score = -1;   
   else 
   { 
      score +=  super_cool_Xheuristic_a(current_state, player, x, y);
      score +=  super_cool_Xheuristic_b(current_state, player, x, y);
   }
   return score;   
}

/*Try to block*/
double super_cool_Xheuristic_a(Game_state *current_state, int player, int x, int y)
{
   int i=0;
   int score=0;
   int max=0;

   max = getMaxBoard(current_state);
   for ( i = 0; i <= max; i++)
   {
      /*if enemy have 2 and we have 0 in the same line.*/
      if (current_state->score_array[1-player][i]==current_state->num_to_connect-2&&current_state->score_array[player][i]==0)
      {
         score-=4;  
      }else if (current_state->score_array[1-player][i]==current_state->num_to_connect-1&&current_state->score_array[player][i]==0)
      {
         score-=10;
      }else if (current_state->score_array[1-player][i]==current_state->num_to_connect-3&&current_state->score_array[player][i]==0)
      {
         score-=1;
      }
   }
   return (double)score/(double)max;
}

/*Try to win*/
double super_cool_Xheuristic_b(Game_state *current_state, int player, int x, int y)
{
   int i=0;
   int score=0;
   int max=0;

   max = getMaxBoard(current_state);
   for ( i = 0; i <= max; i++)
   {
      /*if we have 2 and enemy have 0 in the same line.*/
      if(current_state->score_array[player][i]== 2 && current_state->score_array[1-player][i] == 0)
      { 
         score+= 3;         
      }else if (current_state->score_array[player][i]== 3 && current_state->score_array[1-player][i] == 0)
      {
         score+=8;
      }else if (current_state->score_array[player][i]== 1 && current_state->score_array[1-player][i] == 0)
      {
         score+=1;
      }

   }
   return (double)score/(double)max;
}

/*Loop throuth the board to get the max line numbers*/
int getMaxBoard(Game_state *current_state)
{  
   int max= 0;
   int i = 0;
   int j = 0;
   int k = 0;
   int *line;
   for (i = 0; i <current_state->width; i++)
   {
      for (j = 0; j < current_state->height; j++)
      {
         line = current_state->map[i][j];
         k=0;
         while(line[k]!=-1)
         {
             if (line[k]>=max)
             {
               max = line[k];
             }
             k++;  
         }
      }
   }
   return max;
}
