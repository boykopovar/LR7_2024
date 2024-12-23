#include<iostream>
#include "../include/task_5.h"
#include"../../global_utils.h"


// O(groups)
void print_groups(group* groups)
{

    std::cout<<"-------------------------------------------------\n"
               "| Номер отряда | Список рабов | Тестируемые бочки\n"
               "|--------------|--------------|------------------\n";
    int current_barrel = 1;
    for(int i =0;i<30;++i)
    {
        if(i+1<=9)std::cout<<"|            "<<i+1<<" | ";
        else std::cout<<"|           "<<i+1<<" | ";

        if(groups[i].taster1)std::cout<<"1 ";
        else std::cout<<"  ";

        if(groups[i].taster2)std::cout<<"2 ";
        else std::cout<<"  ";

        if(groups[i].taster3)std::cout<<"3 ";
        else std::cout<<"  ";

        if(groups[i].taster4)std::cout<<"4 ";
        else std::cout<<"  ";

        if(groups[i].taster5)std::cout<<"5 ";
        else std::cout<<"  ";
        std::cout<<"   | ";
        std::cout<<current_barrel<<" - "<<current_barrel+groups[i].count_barrels-1<<'\n';
        current_barrel = current_barrel+groups[i].count_barrels;
    }
    std::cout<<"-------------------------------------------------\n";
}

// O(count)
void print_barrels(barrel* barrels, int start, int count)
{

    std::cout<<"--------------------------------\n"
               "| Номер бочки  | Список рабов  |\n"
               "|--------------|---------------|\n";

    for(int i =0;i<count;++i)
    {
        if(start+i+1<=9)std::cout<<"|            "<<start+i+1<<" | ";
        else std::cout<<"|           "<<start+i+1<<" | ";

        if(barrels[i].taster1)std::cout<<"1 ";
        else std::cout<<"  ";

        if(barrels[i].taster2)std::cout<<"2 ";
        else std::cout<<"  ";

        if(barrels[i].taster3)std::cout<<"3 ";
        else std::cout<<"  ";

        if(barrels[i].taster4)std::cout<<"4 ";
        else std::cout<<"  ";

        if(barrels[i].taster5)std::cout<<"5 ";
        else std::cout<<"  ";
        std::cout<<"   |\n";
    }
    std::cout<<"--------------------------------\n";
}

// O(barrels_count * taster_count)
int find_barrel_by_dead(barrel final_tasters, int start, int taster_count, int barrels_count)
{
    int answer = -2;
    bool tasters[5];

    tasters[0]=final_tasters.taster1;
    tasters[1]=final_tasters.taster2;
    tasters[2]=final_tasters.taster3;
    tasters[3]=final_tasters.taster4;
    tasters[4]=final_tasters.taster5;

    for(int i =0;i<barrels_count;++i)
    {
        for(int j =0;j<taster_count;++j)
        {
            if(combinations30[i][j]==tasters[j])
            {
                if(j==taster_count-1)answer = i+start;
            }
            else break;
        }
    }
    return answer+1;
}

//O(30*find_barrel_by_dead)
void start_next_day()
{
    std::cout<<"\n\n\n ----------------------------- День 2 -----------------------------\n"
               "Поздравляем, пока все рабы живы, значит яд в какой-то из оставшихся 30 бочек\n"
               "     _______         _______         _______         _______         _______\n"
               "    /       \\       /       \\       /       \\       /       \\       /       \\\n"
               "   |         |     |         |     |         |     |         |     |         |\n"
               "   |    1    |     |    2    |     |    3    |     |   ...   |     |   030   |\n"
               "   |         |     |         |     |         |     |         |     |         |\n"
               "    \\_______/       \\_______/       \\_______/       \\_______/       \\_______/\n"
               "Нажмите клавишу Enter, чтобы продолжить...\n";
    check_istream();

    barrel*  barrels = init_barrels(30);
    print_barrels(barrels, 210,30);
    barrel final_tasters = read_dead(5);

    int answer = find_barrel_by_dead(final_tasters, 210, 5, 30);
    std::cout<<"\n-> Отравлена была бочка "<<answer<<" <-\nИгра окончена!\n";

    delete[] barrels;
}


//таблица истинности
const bool combinations30[30][5] = {
        {false, false, false, false, false},
        {true,  false, false, false, false},
        {false, true,  false, false, false},
        {true,  true,  false, false, false},
        {false, false, true,  false, false},
        {true,  false, true,  false, false},
        {false, true,  true,  false, false},
        {true,  true,  true,  false, false},
        {false, false, false, true,  false},
        {true,  false, false, true,  false},
        {false, true,  false, true,  false},
        {true,  true,  false, true,  false},
        {false, false, true,  true,  false},
        {true,  false, true,  true,  false},
        {false, true,  true,  true,  false},
        {true,  true,  true,  true,  false},
        {false, false, false, false, true},
        {true,  false, false, false, true},
        {false, true,  false, false, true},
        {true,  true,  false, false, true},
        {false, false, true,  false, true},
        {true,  false, true,  false, true},
        {false, true,  true,  false, true},
        {true,  true,  true,  false, true},
        {false, false, false, true,  true},
        {true,  false, false, true,  true},
        {false, true,  false, true,  true},
        {true,  true,  false, true,  true},
        {false, false, true,  true,  true},
        {true,  false, true,  true,  true}
};
