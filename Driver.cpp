#include "Tower.hpp"
#include <iostream>
#include <stdlib.h> 

int main()
{
    Tower* t1 = new Tower(1);
    Tower* t2 = new Tower(2);
    Tower* t3 = new Tower(3);
    t1->push(new Disk(6));
    t1->push(new Disk(4));
    t1->push(new Disk(2));

    t1->display();
    t2->display();
    t3->display();
    int winCondition = t1->getCount() - 1;
    
    
while(t3->getCount() <= winCondition)
{
    std::cout <<"Enter the tower from which you would like to remove: "<< "\n";
    int numRemove;
    std::cin >> numRemove;
    std::cout << "Enter which number tower you would like to place it on: " << "\n";
    int numAdd;
    std::cin >> numAdd;

   t1->popThenPushLogic(numRemove, numAdd, t1, t2, t3);
   t1->displayAllTowers(t1, t2, t3);
    
    
}
    std::cout << "You win!" << "\n";
    return 0;
}
