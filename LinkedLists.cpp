//  Erik Pantoja
//  Assignment 2 - Linked List
//  Sept 4th 2019
//  Prof Hwang - Data Structures

//Included Libraries
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// Class Creation - as required per assignment
class Node{
//Public variables
public:
//struct to store different types of student data in array
struct student {
    int studentID;
    string studentName;
    string studentAddress;
    float studentGPA;
};
    student data; // to place in linked list
    Node *next;

    // Class Member functions
    void introduction(); // For readability
    void conclusion(); // For readability
    void printList(Node *node);
    void insert(Node** head_ref, Node::student newerData);
    void insertMiddle(Node* previousNode, Node::student newerData);
    Node* deleteNode(Node* startNode, int deletePostion);
    
};


//Main Function
int main() {
    Node temp;
    temp.introduction(); //For readability
    Node::student array[15]; // Creating array of struct objects with required fields
    array[0].studentID = 5; array[0].studentName = "Bobbie"; array[0].studentAddress = "121 Unknown st"; array[0].studentGPA = 2.3;
    array[1].studentID = 3; array[1].studentName = "Phil"; array[1].studentAddress = "547 Brown st"; array[1].studentGPA = 2.8;
    array[2].studentID = 1; array[2].studentName = "Greg"; array[2].studentAddress = "53 King st"; array[2].studentGPA = 3.7;
    array[3].studentID = 2; array[3].studentName = "Paul"; array[3].studentAddress = "184 Relax st"; array[3].studentGPA = 3.2;
    array[4].studentID = 6; array[4].studentName = "Peggy"; array[4].studentAddress = "592 MLK BLVD"; array[4].studentGPA = 4.0;
    array[5].studentID = 7; array[5].studentName = "Felipe"; array[5].studentAddress = "491 West RD CT"; array[5].studentGPA = 1.6;
    array[6].studentID = 9; array[6].studentName = "Georgie"; array[6].studentAddress = "99 Gray Mist st"; array[6].studentGPA = 3.1;
    array[7].studentID = 8; array[7].studentName = "Wong"; array[7].studentAddress = "5 Cloudbank st"; array[7].studentGPA = 2.9;
    array[8].studentID = 10; array[8].studentName = "Larry"; array[8].studentAddress = "124 Sierra st"; array[8].studentGPA = 3.4;
    array[9].studentID = 13; array[9].studentName = "Monica"; array[9].studentAddress = "53 White BLVD"; array[9].studentGPA = 3.0;
    array[10].studentID = 12; array[10].studentName = "Sarah"; array[10].studentAddress = "1 Jefferson st"; array[10].studentGPA = 1.1;
    array[11].studentID = 11; array[11].studentName = "Tim"; array[11].studentAddress = "32 West st"; array[11].studentGPA = 2.75;
    array[12].studentID = 14; array[12].studentName = "JJ"; array[12].studentAddress = "1030 Green st"; array[12].studentGPA = 3.8;
    array[13].studentID = 4; array[13].studentName = "Craig"; array[13].studentAddress = "43 crusty st"; array[13].studentGPA = 2.7;
    array[14].studentID = 15; array[14].studentName = "Daquan"; array[14].studentAddress = "87 water way"; array[14].studentGPA = 3.5;
    // Displaying the array
    cout << "Unsorted array contents are as follows: " <<endl<<endl;
    for (int i=0; i<15; i++){
        cout << "Student ID: " << array[i].studentID << "   " << " Student Name: " << array[i].studentName << "   " << " Student address: " << array[i].studentAddress << "   " << " Student GPA: " << array[i].studentGPA <<endl;
    }
    cout << endl << "Linked List Display : " <<endl<<endl;
    Node* head = NULL;
    // adding to linked list my inserting
    temp.insert(&head, array[14]); //student 15
    temp.insert(&head, array[12]); //student 14
    temp.insert(&head, array[9]); //student 13
    temp.insert(&head, array[10]); //student 12
    temp.insert(&head, array[11]); //student 11
    temp.insert(&head, array[8]); //student 10
    temp.insert(&head, array[6]); //student 9
    temp.insert(&head, array[7]); //student 8
    temp.insert(&head, array[5]); //student 7
    temp.insert(&head, array[4]); //student 6
    temp.insert(&head, array[0]); //student 5
    temp.insert(&head, array[13]); //student 4
    temp.insert(&head, array[1]); //student 3
    temp.insert(&head, array[3]); //student 2
    temp.insert(&head, array[2]); //student 1
    temp.printList(head);
    // Use Delete function  to delete the kth record from middle of the sorted list - The display
    head = temp.deleteNode(head, 8);
    
    cout << endl << " Display list after using delete here " <<endl<<endl;
    temp.printList(head); // Printing list after deletion
    
    // Insert a mth record to the middle and display the resulting sorted list.
    Node::student arr2[1]; // creating new array to hold a struct instance of new data
    arr2[0].studentID = 16; arr2[0].studentName = "Chance"; arr2[0].studentAddress = "47 Last Chance RD "; arr2[0].studentGPA = 3.40; // Sameple data to add
    temp.insertMiddle(head->next->next->next->next->next->next, arr2[0]); //inserting into middle of linked list
    
    cout << endl << " Display list after using insert here " <<endl<<endl;;
    temp.printList(head);
    
    temp.conclusion(); //For readability
    return 0;
}


void Node::introduction(){
    cout <<"Asssignment 2 Link List - and Un-Sorted array program " << endl <<endl;
}

void Node::conclusion(){
    cout << endl << "Created by Erik Pantoja, For Data Structures Fall 2019 "<<endl<<endl;
}

//Function to print out the linked list
void Node::printList(Node *node)
{
    while (node != NULL) // Making sure the node is not empty
    {
        //Printing each field of the struct
        cout << "Student ID: " << node-> data.studentID << " " ;
        cout << "Student name: " << node-> data.studentName << "   ";
        cout << "Student Address: " << node -> data.studentAddress << "   ";
        cout << "Student GPA: " << node -> data.studentGPA << "   ";
        cout <<endl;
        
        node = node->next; // Moving into the next node to print
    }
    cout << endl;
}

//Insert function for linked list - in a push sort of manner
void Node::insert(Node** headNode, Node::student newerData)
{
    Node* new_node = new Node();
    new_node->data = newerData;
    new_node->next = (*headNode);
    (*headNode) = new_node;
}

//Function to insert after - to place in the middle of list if needed
void Node::insertMiddle(Node* previousNode, Node::student newerData)
{
    if (previousNode == NULL) // Making sure the list is still going
    {
        return;
    }
    
    Node* newNode = new Node();
    newNode -> data = newerData;
    newNode -> next = previousNode -> next;
    previousNode -> next = newNode;
}

//Function to delete from the linked list
Node* Node::deleteNode(Node* startNode, int deletePostion)
{
    if (deletePostion < 1) //if number entered is less then 1
        return startNode;
    if (startNode == NULL) //if list is empty
        return NULL;
    
    if (deletePostion == 1)
    {
        Node *res = startNode -> next;
        delete(startNode); // deletes node
        return res;
    }
    startNode -> next = deleteNode (startNode ->next, deletePostion - 1);
    return startNode; // returns beginning node
}
