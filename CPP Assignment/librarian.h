#include <bits/stdc++.h>
#include "userfunctions.h"

using namespace std;

void librarianDisplay()
{
    cout << "\n<<------------Librarian Interface------------->>\n";
    cout << "\nType 1 to add a user." << endl;
    cout << "Type 2 to update a user." << endl;
    cout << "Type 3 to delete a user." << endl;
    cout << "Type 4 to list down all books." << endl;
    cout << "Type 5 to list down all users." << endl;
    cout << "Type 6 to check which book is issued to which user." << endl;
    cout << "Type 7 to check list of books issue to user." << endl;
    cout << "Type 8 to add a book." << endl;
    cout << "Type 9 to update a book." << endl;
    cout << "Type 10 to delete a book." << endl;
    cout << "Type 0 to exit." << endl;

    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        addUser();
        break;
    case 2:
        update_user();
        break;
    case 3:
        deleteUser();
        break;
    case 4:
        listbooks();
        break;
    case 5:
        listUsers();
        break;
    case 6:
        bookissued();
        break;
    case 7:
        userissued_books();
        break;
    case 8:
        addbook();
        break;
    case 9:
        updatebook();
        break;
    case 10:
        deletebook();
        break;

    case 0:
        cout << "\nLogged out sucessfully!!\n";
        cout << "\n<<------------------------>>\n";
        return;

    default:
        cout << "\nKindly enter a valid choice.\n";
        break;
    }
    librarianDisplay();
}

void librarianLogin()
{
    string id, pass;
    cout << "\nPlease enter your user_id: ";
    cin >> id;
    cout << "Please enter your password: ";
    cin >> pass;

    string rowText;

    ifstream MyReadFile("userList.txt");
    string word;
    vector<string> row;
    int found = 0;

    while (getline(MyReadFile, rowText))
    {
        stringstream str(rowText);
        row.clear();
        while (getline(str, word, ','))
        {
            row.push_back(word);
        }

        if (row[1] == id && row[3] == "librarian")
        {
            found++;
            if (row[2] == pass)
            {
                MyReadFile.close();
                librarianDisplay();
            }
            else
            {
                cout << "\nUser not found!!\nKindly enter correct user_id/password.\n";
                librarianLogin();
            }
        }
    }
    if (found == 0)
    {
        cout << "\nUser not found!!\nKindly enter correct user_id/password.\n";
        librarianLogin();
    }

    MyReadFile.close();
}