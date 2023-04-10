//  main.cpp
//  Assignment 4
//
//  Created by Jordyn O’Brien on 2022-11-07.
//

#include <iostream>
using namespace std;

class book {
public:
    
    string title;
    string author;
    string pub;
    string pubYear;
    string inum;
    book* next;
    book(){
        next = NULL;
    }
    
};

class bookList{

    book* head;
public:
    bookList(){
        head = NULL;
    }
    book* add_node(book *head);
    void print_list(book *head);
    void delete_list(book ** head, int position);
};


book* bookList::add_node (book*head){
//Getting user input

//Creating a new book in dynamic memory and assigning it to 'temp'
    book* temp= new book;
//Assigning user input to the book
    cout << "Enter book title: " << endl;
    cin.ignore();
    getline(cin,temp -> title);
    cout << "Enter author's name:" << endl;
    getline(cin, temp -> author);
    cout << "Enter publisher:" << endl;
    getline(cin, temp -> pub);
    cout << "Enter year published: ";
    cin >> temp -> pubYear;
    cout << "Enter ISBN number: ";
    cin >> temp -> inum;
    temp -> next = head;
// The new book becomes the head, pushing previously entered books forward
    head = temp;
    return head;
}

void bookList::print_list(book* head ){
// count created to count how many times loop is executed (Used to number books)
    int count = 0;
// for loop prints head of list then changes head to the next
    for ( ; head; head = head->next ){
        count++;
        cout<< "Book: "<< count<< endl;
        cout << "Title: " << head->title << endl;
        cout << "Author: " << head->author << endl;
        cout << "Publisher: " << head->pub << endl;
        cout << "Year Published: " << head->pubYear << endl;
        cout << "ISBN Number: " << head->inum << endl;
      
      }

}

void bookList::delete_list(book** head, int booknum){
    book* temp= *head;
    book* prev= *head;

    for (int i = 0; i < booknum; i++) {
        if (i == 0 && booknum == 1) {
            *head = (*head)->next;
            delete(temp);
           }
        else {
            if (i == booknum - 1 && temp) {
                prev->next = temp->next;
                delete(temp);
               }
        else {
            prev = temp;
            if (prev == NULL){
                break;}
            temp = temp->next;
               }
           }
       }
}

int main() {

    bookList list;
    
//Define head pointer and setting to NULL
    book* head = NULL;
//While loop to repeat switch case until Q is entered
    while(true){
        char choice;
        cout << "Add book details [A]" << endl << "Print book details [P]" << endl;
        cout << "Delete book details [D]" << endl << "Quit [Q]" << endl;
        cin >> choice;
// Switch case to call functions
        switch (choice){
            case 'A':
                head = list.add_node(head);
                break;
            case 'P':
                list.print_list(head);
                break;
            case 'Q':
                return 0;
            case 'D':
                int select;
                cout << "Which book would you like to delete?"<< endl;
                cin >> select;
                list.delete_list(&head,select);
                break;
        }}}

