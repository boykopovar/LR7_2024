#include<iostream>
#include "task_5.h"
#include"../global_utils.h"




void print_barrels()
{
    std::cout<<"     _______         _______         _______         _______         _______\n"
               "    /       \\       /       \\       /       \\       /       \\       /       \\\n"
               "   |         |     |         |     |         |     |         |     |         |\n"
               "   |    1    |     |    2    |     |    3    |     |   ...   |     |   240   |\n"
               "   |         |     |         |     |         |     |         |     |         |\n"
               "    \\_______/       \\_______/       \\_______/       \\_______/       \\_______/";
}




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

void print_barrels(barrel* barrels, int start, int count)
{

    std::cout<<"-------------------------------\n"
               "| Номер бочки  | Список рабов |\n"
               "|--------------|--------------|\n";

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
    std::cout<<"-------------------------------\n";
}

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
    getch();
    barrel*  barrels = init_barrels(30);
    print_barrels(barrels, 0,30);
    barrel final_tasters = read_dead(5);
    int answer = find_barrel_by_dead(final_tasters, 0, 5, 30);
    std::cout<<"\n-> Отравлена была бочка "<<answer<<" <-\nИгра окончена!\n";

    delete[] barrels;
}

void continue_first(int dead_group)
{
    if(dead_group>=0 && dead_group<=4)
    {
        std::cout<<"\n\n\n ----------------------------- День 2 -----------------------------\n"
                   "Круг подозрительных бочек удалось сузить до 16 штук и у нас осталось еще 4 раба!\n"
                   "Для удобства оставшихся рабов пронумеруем от 1 до 4\n"
                   "     _______         _______         _______         _______         _______\n"
                   "    /       \\       /       \\       /       \\       /       \\       /       \\\n"
                   "   |         |     |         |     |         |     |         |     |         |\n"
                   "   |    1    |     |    2    |     |    3    |     |   ...   |     |   016   |\n"
                   "   |         |     |         |     |         |     |         |     |         |\n"
                   "    \\_______/       \\_______/       \\_______/       \\_______/       \\_______/\n"
                   "Нажмите клавишу Enter, чтобы продолжить...\n";
        getch();
        barrel*  barrels = init_barrels(16);
        print_barrels(barrels, dead_group*16,16);
        barrel final_tasters = read_dead(4);
        int answer = find_barrel_by_dead(final_tasters, dead_group*16, 4, 16);
        std::cout<<"\n-> Отравлена была бочка "<<answer<<" <-\nИгра окончена!\n";

        delete[] barrels;
    }
    else if(dead_group>=5 && dead_group<=14)
    {
        std::cout<<"\n\n\n ----------------------------- День 2 -----------------------------\n"
                   "Круг подозрительных бочек удалось сузить до 8 штук и у нас осталось еще 3 раба!\n"
                   "Для удобства оставшихся рабов пронумеруем от 1 до 3\n"
                   "     _______         _______         _______         _______         _______\n"
                   "    /       \\       /       \\       /       \\       /       \\       /       \\\n"
                   "   |         |     |         |     |         |     |         |     |         |\n"
                   "   |    1    |     |    2    |     |    3    |     |   ...   |     |   008   |\n"
                   "   |         |     |         |     |         |     |         |     |         |\n"
                   "    \\_______/       \\_______/       \\_______/       \\_______/       \\_______/\n"
                   "Нажмите клавишу Enter, чтобы продолжить...\n";
        getch();
        barrel*  barrels = init_barrels(8);
        print_barrels(barrels, 80+(dead_group-5)*8,8);
        barrel final_tasters = read_dead(3);
        int answer = find_barrel_by_dead(final_tasters, 80+(dead_group-5)*8, 3, 8);
        std::cout<<"\n-> Отравлена была бочка "<<answer<<" <-\nИгра окончена!\n";

        delete[] barrels;
    }
    else if(dead_group>=15 && dead_group<=24)
    {
        std::cout<<"\n\n\n ----------------------------- День 2 -----------------------------\n"
                   "Круг подозрительных бочек удалось сузить до 4 штук и у нас осталось еще 2 раба!\n"
                   "Для удобства оставшихся рабов пронумеруем от 1 до 2\n"
                   "     _______         _______         _______         _______   \n"
                   "    /       \\       /       \\       /       \\       /       \\\n"
                   "   |         |     |         |     |         |     |         |   \n"
                   "   |    1    |     |    2    |     |    3    |     |    4    |   \n"
                   "   |         |     |         |     |         |     |         |   \n"
                   "    \\_______/       \\_______/       \\_______/       \\_______/\n"
                   "Нажмите клавишу Enter, чтобы продолжить...\n";
        getch();
        barrel*  barrels = init_barrels(4);
        print_barrels(barrels, 160+(dead_group-15)*4,4);
        barrel final_tasters = read_dead(2);
        int answer = find_barrel_by_dead(final_tasters, 160+(dead_group-15)*4, 2, 4);
        std::cout<<"\n-> Отравлена была бочка "<<answer<<" <-\nИгра окончена!\n";

        delete[] barrels;
    }
    else if(dead_group>=25 && dead_group<=29)
    {
        std::cout<<"\n\n\n ----------------------------- День 2 -----------------------------\n"
                   "Круг подозрительных бочек удалось сузить до 4 штук и у нас осталось еще 2 раба!\n"
                   "Для удобства оставшихся рабов пронумеруем от 1 до 2\n"
                   "     _______         _______         _______         _______   \n"
                   "    /       \\       /       \\       /       \\       /       \\\n"
                   "   |         |     |         |     |         |     |         |   \n"
                   "   |    1    |     |    2    |     |    3    |     |    4    |   \n"
                   "   |         |     |         |     |         |     |         |   \n"
                   "    \\_______/       \\_______/       \\_______/       \\_______/\n"
                   "Нажмите клавишу Enter, чтобы продолжить...\n";
        getch();
        barrel*  barrels = init_barrels(2);
        print_barrels(barrels, 200+(dead_group-25)*2,2);
        barrel final_tasters = read_dead(1);
        int answer = find_barrel_by_dead(final_tasters, 200+(dead_group-25)*2, 1, 2);
        std::cout<<"\n-> Отравлена была бочка "<<answer<<" <-\nИгра окончена!\n";

        delete[] barrels;
    }
    else std::cout<<"Вы жульничаете!\n";
}

const bool combinations30[30][5] = {
        {false, false, false, false, false},  // 1
        {true,  false, false, false, false},  // 2
        {false, true,  false, false, false},  // 3
        {true,  true,  false, false, false},  // 4
        {false, false, true,  false, false},  // 5
        {true,  false, true,  false, false},  // 6
        {false, true,  true,  false, false},  // 7
        {true,  true,  true,  false, false},  // 8
        {false, false, false, true,  false},  // 9
        {true,  false, false, true,  false},  // 10
        {false, true,  false, true,  false},  // 11
        {true,  true,  false, true,  false},  // 12
        {false, false, true,  true,  false},  // 13
        {true,  false, true,  true,  false},  // 14
        {false, true,  true,  true,  false},  // 15
        {true,  true,  true,  true,  false},  // 16
        {false, false, false, false, true},   // 17
        {true,  false, false, false, true},   // 18
        {false, true,  false, false, true},   // 19
        {true,  true,  false, false, true},   // 20
        {false, false, true,  false, true},   // 21
        {true,  false, true,  false, true},   // 22
        {false, true,  true,  false, true},   // 23
        {true,  true,  true,  false, true},   // 24
        {false, false, false, true,  true},   // 25
        {true,  false, false, true,  true},   // 26
        {false, true,  false, true,  true},   // 27
        {true,  true,  false, true,  true},   // 28
        {false, false, true,  true,  true},   // 29
        {true,  false, true,  true,  true}    // 30
};
