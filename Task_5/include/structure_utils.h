#pragma once

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

group create_group(int count_barrels, const int* tasters, int tasters_count);
group* init_groups();
barrel* init_barrels(int count);
barrel read_dead(int count);