#include "Stack.hpp"
#include <iostream>
#include <stdlib.h> 

int main()
{
    Stack* stackOne = new Stack();
    Stack* stackTwo = new Stack();
    Stack* stackThree = new Stack();

    stackOne->push(3);
    stackOne->push(2);
    stackOne->push(1);

    stackOne->display();

    stackOne->pushThenPop(stackTwo);

    
    stackOne->display3Stacks(stackOne, stackTwo, stackThree);
    


    return 0;
}