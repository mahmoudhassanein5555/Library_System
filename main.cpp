
#include <climits>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
#include <deque>
#include <queue>
#define el '\n'
#define ll long long
#include <iostream>
using namespace std;
class Book
{
private:
     string author, title;
     int id, copies;

public:
     void set_id(int ID)
     {
          id = ID;
     }
     void set_copies(int COPIES)
     {
          copies = COPIES;
     }
     void set_author(string AUTHOR)
     {
          author = AUTHOR;
     }
     void set_title(string TITLE)
     {
          title = TITLE;
     }
     string get_author()
     {
          return author;
     }
     string get_title()
     {
          return title;
     }
     int get_id()
     {
          return id;
     }
     int get_copies()
     {
          return copies;
     }
     void print_all_details()
     {
          cout << "The Author of the book : " << "<< " << author << " >>" << el;

          cout << "The Title of the book : " << "<< " << title << " >>" << el;

          cout << "The ID of the book : " << "<< " << id << " >>" << el;

          cout << "Number of Copies of the book : " << "<< " << copies << " >>" << el;
     }
};
int main()
{
     vector<Book> library;
               cout << "\n========= Library Menu =========\n";
          cout << "1. Add a new book\n";
          cout << "2. Search for a book by ID\n";
          cout << "3. Delete a book by ID\n";
          cout << "4. Update book information by ID\n";
          cout << "5. Display all books\n";
          cout << "0. Exit\n";
          cout << "Enter your choice: ";
     while (true)
     {

          int choice;
          cin >> choice;
          if (choice == 1)
          {
               Book b;
               cout << "Enter the title of the book \n";
               string title;
               cin >> title;
               b.set_title(title);
               cout << "Enter the Author of the book \n";
               string Author;
               cin >> Author;
               b.set_author(Author);
               cout << "Enter the ID of the book \n";
               int id;
               cin >> id;
               b.set_id(id);
               cout << "Enter the copies of the book \n";
               int copies;
               cin >> copies;
               b.set_copies(copies);
               library.push_back(b);
          }
          else if (choice == 2)
          {
               cout << "pls enter the ID of the book \n";
               int id;
               cin >> id;
               bool found = false;
               for (int i = 0; i < library.size(); i++)
               {
                    if (library[i].get_id() == id)
                    {
                         cout << " -exist- " << el;
                         found = true;
                         break;
                    }
               }
               if (!found)
               {
                    cout << "not found\n";
               }
          }
          else if (choice == 3)
          {
               cout << " pls enter the id " << el;
               int id;
               cin >> id;
               for (int i = 0; i < library.size(); i++)
               {
                    if (library[i].get_id() == id)
                    {
                         library.erase(library.begin() + i);
                         break;
                    }
               }
          }
          else if (choice == 4)
          {
               cout << "pls enter the ID of the book \n";
               int id;
               cin >> id;
               cout << "========== Edit Book ==========\n";
               cout << "Choose the field you want to edit:\n";
               cout << "1. Edit Author Name\n";
               cout << "2. Edit Title\n";
               cout << "3. Edit ID\n";
               cout << "4. Edit Number of Copies\n";
               cout << "5. Cancel\n";
               cout << "================================\n";
               cout << "Enter your choice: ";
               int choice;
               cin >> choice;
               bool found = false;
               for (int i = 0; i < library.size(); i++)
               {
                    if (library[i].get_id() == id)
                    {
                         if (choice == 1)
                         {
                              string Author;
                              cin >> Author;
                              library[i].set_author(Author);
                         }
                         else if (choice == 2)
                         {
                              string title;
                              cin >> title;
                              library[i].set_title(title);
                         }
                         else if (choice == 3)
                         {
                              int id;
                              cin >> id;
                              library[i].set_id(id);
                         }
                         else if (choice == 4)
                         {
                              int copies;
                              cin >> copies;
                              library[i].set_copies(copies);
                         }
                         found = true;
                         break;
                    }
               }
               if (!found)
               {
                    cout << "Book with this ID not found!\n";
               }
          }
          else if (choice == 5)
          {
               int counter = 1;
               for (int i = 0; i < library.size(); i++)
               {
                    cout << "\n====== Book " << counter++ << " ======\n";
                    library[i].print_all_details();
               }
          }
          else if (choice == 0)
          {
               cout << "The program will end :( " << el;
               break;
          }
     }
     return 0;
}
