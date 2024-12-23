#include<iostream>
#include "../include/task_5.h"
#include"../../global_utils.h"


//O(tasters_count)
group create_group(int count_barrels, const int* tasters, int tasters_count)
{
    group current_group;
    current_group.count_barrels = count_barrels;

    for(int i=0;i<tasters_count;++i)
    {
        switch(tasters[i])
        {
            case 1: current_group.taster1 = true; break;
            case 2: current_group.taster2 = true; break;
            case 3: current_group.taster3 = true; break;
            case 4: current_group.taster4 = true; break;
            case 5: current_group.taster5 = true; break;
        }
    }
    return current_group;
}

//O(tasters_count)
group create_barrel(int count_barrels, const int* tasters, int tasters_count)
{
    group current_group;
    current_group.count_barrels = count_barrels;

    for(int i=0;i<tasters_count;++i)
    {
        switch(tasters[i])
        {
            case 1: current_group.taster1 = true; break;
            case 2: current_group.taster2 = true; break;
            case 3: current_group.taster3 = true; break;
            case 4: current_group.taster4 = true; break;
            case 5: current_group.taster5 = true; break;
        }
    }
    return current_group;
}

//O(groups_count * tasters_count) в задаче фактически 30
group* init_groups()
{
    int index = 0;
    auto* groups = new group[30];

    // по 16 бочек
    int tasters_16[][1] = {{1}, {2}, {3}, {4}, {5}};
    for (int i = 0; i < 5; ++i)
    {
        groups[index++] = create_group(16, tasters_16[i], 1);
    }

    // по 8 бочек
    int tasters_8[][2] = {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};
    for (int i = 0; i < 10; ++i)
    {
        groups[index++] = create_group(8, tasters_8[i], 2);
    }

    //по 4
    int tasters_4[][3] = {{1, 2, 3}, {1, 2, 4}, {1, 2, 5}, {1, 3, 4}, {1, 3, 5}, {1, 4, 5}, {2, 3, 4}, {2, 3, 5}, {2, 4, 5}, {3, 4, 5}};
    for (int i = 0; i < 10; ++i)
    {
        groups[index++] = create_group(4, tasters_4[i], 3);
    }

    // по 2
    int tasters_2[][4] = {{1, 2, 3, 4}, {1, 2, 3, 5}, {1, 2, 4, 5}, {1, 3, 4, 5}, {2, 3, 4, 5}};
    for(int i = 0; i < 5; ++i)
    {
        groups[index++] = create_group(2, tasters_2[i], 4);
    }
    return groups;
}

// O(count)
barrel* init_barrels(int count)
{

    auto* barrels = new barrel[count];
    for(int i =0;i<count;++i)
    {
        barrels[i].taster1 = combinations30[i][0];
        barrels[i].taster2 = combinations30[i][1];
        barrels[i].taster3 = combinations30[i][2];
        barrels[i].taster4 = combinations30[i][3];
        barrels[i].taster5 = combinations30[i][4];
    }
    return barrels;
}

// O(count)
barrel read_dead(int count)
{
    barrel tasters;
    for(int i = 1;i<=count;++i)
    {
        std::cout<<"\nМёртв ли РАБ "<<i<<"?\n1 - Да\n0 - Нет\n";
        bool alive = false;
        std::cin>>alive;
        if(!check_istream())alive = false;
        switch(i)
        {
            case 1: tasters.taster1 = alive;
            case 2: tasters.taster2 = alive;
            case 3: tasters.taster3 = alive;
            case 4: tasters.taster4 = alive;
            default: tasters.taster5 = alive;
        }
    }
    return tasters;
}
