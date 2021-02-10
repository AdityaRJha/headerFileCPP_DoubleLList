#pragma once
#if !defined(DLL_H)
#define DLL_H
#include <string>

struct student
{
    std::string name;
    int age;
    double fee;
};

struct node
{
    student data;
    node* next;
    node* prev;
};

class dll
{
private:
    /* data */
    node* head;
    node* tail;
    int num;

    node* createNode();
    node* selectNode();
    void printstu(student);
    void deleteNode(node*);
public:
    dll(/* args */);
    void insertSorted();
    int numOfElements();
    bool check();
    void printHead();
    void printTail();
    void deleteSelNode();
    ~dll();
};


#endif