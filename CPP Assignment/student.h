#include <bits/stdc++.h>
#include "booksfunctions.h"

using namespace std;

void studentDisplay(string user_id)
{
    cout << "\n<<------------Student Interface------------->>\n";
    cout << "\nType 1 to see all the books." << endl;
    cout << "Type 2 to see the list of books you have." << endl;
    cout << "Type 3 to check whether a book is available to issue or not." << endl;
    cout << "Type 4 to issue a book." << endl;
    cout << "Type 5 to return a book and clear fine(if any)." << endl;
    cout << "Type 6 to display the fine amount." << endl;
    cout << "Type 7 to display the due date of all the books you have issued." << endl;
    cout << "Type 0 to exit." << endl;

    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        listbooks();
        break;
    case 2:
        userissued(user_id);
        break;
    case 3:
        checkavailability();
        break;
    case 4:
        issuebook(user_id, 3);
        break;
    case 5:
        returnbook(user_id, 3);
        break;
    case 6:
        displayfine(user_id, 3);
        break;
    case 7:
        display_due_date(user_id, 3);
        break;

    case 0:
        cout << "\nLogged out sucessfully!!\n";
        cout << "\n<<------------------------>>\n";
        return;

    default:
        cout << "\nKindly enter a valid choice.\n";
        break;
    }
    studentDisplay(user_id);
}

void studentLogin()
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

        if (row[1] == id && row[3] == "student")
        {
            found++;
            if (row[2] == pass)
            {
                studentDisplay(id);
            }
            else
            {
                cout << "Password is incorrect!";
                studentLogin();
            }
        }
    }
    if (found == 0)
    {
        cout << "Student not found!" << endl;
        studentLogin();
    }

    MyReadFile.close();
}