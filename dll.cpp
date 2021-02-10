#include "dll.hpp"
#include <iostream>

using namespace std;

dll::dll(/* args */)
{
    head -> next = tail;
    tail->prev = head;
    num = 0;
}


node* dll::createNode()
{
    node* send = new node();
    cout<<"\nEnter the first name of student.\t";
    cin>>send->data.name;
    cout<<"\nEnter age.\t";
    cin>>send->data.age;
    cout<<"\nEnter fees.\t";
    cin>>send->data.fee;
    ++num;
    return send;
}

bool nCaseCompare(const string& str1, const string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    for (string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2) {
        if (tolower(static_cast<unsigned char>(*c1)) != tolower(static_cast<unsigned char>(*c2))) {
            return false;
        }
    }
    return true;
}

node* dll::selectNode()
{
    string findName;
    int age;
    char choose;
    node* temp = head;
    printHead();
    cout<<"\nEnter the name of the student.";
    cin>>findName;
    cout<<"\nEnter age.";
    cin>>age;
    while (temp != NULL)
    {
        if(nCaseCompare(temp->data.name, findName) && temp->data.age == age)
            return temp;
    }
    cout<<"\nData not found, Enter again [Y/N]";
    cin>>choose;
    if (choose == 'y' || choose == 'Y')
    {
        selectNode();
    }
    else if (choose == 'y' || choose == 'Y')
    {
        return NULL;
    }
    else
    {
        cout<<"ABORTING!!!!!!!";
        return NULL;
    }
    return NULL;
}

void dll::insertSorted()
{
    int age;
    node* temp = head;
    node* newNode = createNode();
    age = newNode->data.age;
    if(age >= tail->data.age)
    {
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
    }
    else if (age <= head->data.age)
    {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
    else
    {
        while(temp ->next != NULL)
        {
            if (temp -> next ->data.age <= age && temp ->next ->next ->data.age > age)
            {
                newNode -> next = temp ->next ->next;
                temp ->next = newNode;
                ++num;
                return;
            }
            else if (temp ->next == NULL && temp ->next ->data.age <= age)
            {
                temp ->next = newNode;
                ++num;
                return;
            }
            else if(temp -> next ->data.age <= age && temp ->next ->next == NULL)
            {
                newNode -> next = temp ->next ->next;
                temp ->next = newNode;
                ++num;
                return;
            }
            temp = temp ->next;
        }
    }
    
}

void dll::deleteNode(node * delNode)
{
    delNode->next->prev = delNode ->prev;
    delNode->prev->next = delNode ->next;
    --num;
    delete[] delNode;
    delete delNode;
}

void dll::deleteSelNode()
{
    node* delNode = selectNode();
    deleteNode(delNode);
}

int dll::numOfElements()
{
    return num;
}

bool dll::check()
{
    node* foundNode = selectNode();
    if (foundNode != NULL)
    {
        return true;
    }
    return false;
     
}

void dll::printstu(student printNode)
{
    cout<<printNode.name<<"\n\tAge: "<<printNode.age<<"\n\tFee: $"<<printNode.fee<<endl;
}

void dll::printHead()
{
    int number = 0;
    node* temp = head;
    while (temp ->next!=NULL)
    {
        cout<<number;
        printstu(temp->data);
        temp=temp ->next;
        ++number;
    }
    
}

void dll::printTail()
{
    int number = num;
    node* temp = head;
    while (temp ->next!=NULL)
    {
        cout<<number;
        printstu(temp->data);
        temp=temp ->next;
        --number;
    }
}

dll::~dll()
{
    node* temp = head;
    while (temp->next != NULL)
    {
        delete[] temp;
    }    
}