#include "Tower.hpp"
#include "iostream"

Tower::Tower(int towerNumber)
{
    this->top = 0;
    this->count = 0; 
    this->towerNumber = towerNumber;
}


int Tower::getCount()
{
    return this->count;
}


Tower * Tower::pickFrom3Towers(int i, Tower * t1, Tower * t2, Tower * t3)
{
    if(i == 1)
    {
        return t1;
    }

    else if(i == 2)
    {
        return t2;
    }

    else if(i == 3)
    {
        return t3;
    }

    else
    {
        return 0;
    }
    
}

void Tower::popThenPushLogic(int removeListNum, int addListNum, Tower * t1, Tower * t2,Tower * t3)
{
    Tower* towerRemove = pickFrom3Towers(removeListNum, t1, t2, t3);
    Tower* towerAdd = pickFrom3Towers(addListNum, t1, t2, t3);

    if(!towerRemove -> top)
    {
        std::cout << "There is nothing to remove"<< "\n";
        return;
    }
    else if(!towerAdd -> top)
    {
       towerAdd->push(towerRemove->pop());
       return;
    }
    else if(towerRemove->top->getSize() > towerAdd->top->getSize())
    {
       std::cout << "Invalid move"<< "\n";
       return;
    }
    else
    {
        towerAdd->push(towerRemove->pop());
    }
    
}
void Tower::displayAllTowers(Tower* t1, Tower* t2, Tower* t3)
 {
     t1->display();
     t2->display();
     t3->display();
     std::cout << "\n";
 }

void Tower::push(Disk* d)
{
    if(this->top)
    {

        if(d->getSize() > this->top->getSize())
        {
            std::cout << "Error, too big " << "\n";
        }

        else if(d->getSize() < this->top->getSize())
        {
            d->setNextDisk(this->top);
            this->top = d;
            this->count++;
        }
    }
        else
        {
            this->top = d;
            this->count++;
        }
}

Disk* Tower::pop()
{
    if(this->count > 0) //if(this->head)
    {
    Disk* diskToReturn = this->top;
    this->top = this->top->getNextDisk();
    this->count--;
    diskToReturn->setNextDisk(0);
    return diskToReturn;
    }
    
    return 0;
}
        
Disk* Tower::peek()
{
    return this->top;
}

void Tower::display()
{
    std::cout <<"Tower " << this->towerNumber << "\n";
    Disk* currDisk = this->top;
    for(int i = 0; i < this->count; i++)
    {
        currDisk->display();
        currDisk = currDisk->getNextDisk();

    }
    if(count == 0)
    {
        std::cout << "----------\n";
    }
    
    
}