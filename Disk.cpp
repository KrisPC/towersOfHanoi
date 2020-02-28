#include "Disk.hpp"
#include "iostream"


 int Disk::getSize()
 {
    return this->size;
 }


void Disk::display()
{
    for(int i = 0; i <= this->size; i ++)
    {
        std::cout << "=";
    }
    std::cout << "\n";
}


Disk::Disk(int size)
{
    this->size = size;
    this->nextDisk = 0;
}

 Disk* Disk::getNextDisk()
 {
     return this->nextDisk;
 }

 void Disk::setNextDisk(Disk* d)
 {
     this->nextDisk = d;
 }