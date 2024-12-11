#pragma once
#include<conio.h>


typedef struct barrel
{
    bool taster1 = false;
    bool taster2 = false;
    bool taster3 = false;
    bool taster4 = false;
    bool taster5 = false;
} barrel;
typedef struct group
{
    int count_barrels = 0;
    bool taster1 = false;
    bool taster2 = false;
    bool taster3 = false;
    bool taster4 = false;
    bool taster5 = false;
} group;

extern const bool combinations30[30][5];

void task5();
void print_barrels();
void continue_first(int dead_group);

group create_group(int count_barrels, const int* tasters, int tasters_count);
group* init_groups();
barrel* init_barrels(int count);
void print_barrels(barrel* barrels, int start, int count);
barrel read_dead(int count);
int find_barrel_by_dead(barrel final_tasters, int start, int taster_count, int barrels_count);
void print_groups(group* groups);
void start_next_day();

