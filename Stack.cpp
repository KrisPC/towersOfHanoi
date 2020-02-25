#include "Stack.hpp"
#include <iostream>
#include <stdlib.h>

Stack::Stack()
{
    this->top = 0;
}

void Stack::pushThenPop(Stack* s)
{
    int value = this->peek();
    this->pop();
    s->push(value);

}

void Stack::display3Stacks(Stack* s1, Stack* s2, Stack* s3)
{
    std::cout << "Stack one: " << "\n";
    s1->display();
    std::cout << "Stack two: " << "\n";
    s2->display();
    std::cout << "Stack three: " << "\n";
    s3->display();
}

void Stack::push(int payload)
{
    Node* n = new Node(payload);
    if(top)
    {
        //we have at least one element on our stack
        n->setNextNode(this->top);
        this->top = n;
    }
    else
    {
        this->top = n;
    }
    
}

int Stack::pop()
{
    int valueToReturn = this->top->getPayload();
    Node* temp = this->top;
    top = top->getNextNode();
    temp->setNextNode(0);
    delete temp;
    return valueToReturn;
}

int Stack::peek()
{
    return this->top->getPayload();
}

void Stack::display()
{
    if(this->top)
    {
        Node* currNode = this->top;
        while(currNode)
        {
            std::cout << currNode->getPayload() << "\n";
            currNode = currNode->getNextNode();
        }
    }
    else
    {
        std::cout << "Empty Stack\n";
    }
}