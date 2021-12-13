#pragma once
void init_field(char** field, int size);
void print_field(char** field, int size);
void player_turn(char** field, int size);
bool check_win(char** field, int size, char sign);
bool check_draw(char** field, int size);