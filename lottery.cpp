/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "lottery.h"
#include "general.h"
#define 	UUID_LEN   40
#define 	MAX_TIP_LEN   17
#define 	MAX_LINE_LEN   (UUID_LEN + 1 + MAX_TIP_LEN + 1)
#define   TIP_SIZE 6
#include "string.h"
#include <stdlib.h>

int tips_array[1000000][TIP_SIZE];

bool init_lottery(const char * csv_file, char csv_separator){
  const char* thing = &csv_separator;
  FILE* fd = fopen(csv_file, "r");
  int i = 0;
  if(fd != NULL){
    while(!feof(fd)){
      int a = 0;
      char* seperated_thing;
      char* tips[TIP_SIZE] = {0};
      char line[MAX_LINE_LEN] = {0};
      fgets(line,MAX_LINE_LEN, fd);
      seperated_thing = strtok(line, thing);
      for(int a = 0; a < TIP_SIZE; a++){
        seperated_thing = strtok(NULL, thing);
        if(seperated_thing == NULL){tips[a] = ""; tips_array[i][a] = atoi(tips[a]);}
        else{tips_array[i][a] = atoi(seperated_thing);}
      }
      i++;
    }
    return true;
  }
  return false;
}
bool set_drawing(int drawing_numbers[TIP_SIZE]){
  if(drawing_numbers == NULL){
    return false;
  }
  if(drawing_numbers[TIP_SIZE] < 0 || drawing_numbers[TIP_SIZE] > 45)return false;


  return true;
}
int get_tip_result(int tip_number){
  if(tip_number > 42 || tip_number < 0)return -2;
  return -1;
}
bool get_tip(int tip_number, int tip[TIP_SIZE]){
  if(tip_number > -1 && tip_number < 46){
    for(int i = 0; i < TIP_SIZE; i++){
      tip[i] = tips_array[tip_number][i];
    }
    return true;
  }
  return false;
}
int get_right_tips_count(int right_digits_count){
  if(!set_drawing(&right_digits_count) || right_digits_count <= 0 || right_digits_count > TIP_SIZE)return -1;
  return 1;
}
