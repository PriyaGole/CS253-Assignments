#include <bits/stdc++.h>

using namespace std;

void professorDisplay(string user_id)
{
    cout << "\n<<------------Professor Interface------------->>\n";
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
        issuebook(user_id, 2);
        break;
    case 5:
        returnbook(user_id, 2);
        break;
    case 6:
        displayfine(user_id, 2);
        break;
    case 7:
        display_due_date(user_id, 2);
        break;

    case 0:
        cout << "\nLogged out sucessfully!!\n";
        cout << "\n<<------------------------>>\n";
        return;

    default:
        cout << "\nKindly enter a valid choice.\n";
        break;
    }
    professorDisplay(user_id);
}

void professorLogin()
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

        if (row[1] == id && row[3] == "professor")
        {
            found++;
            if (row[2] == pass)
            {
                professorDisplay(id);
            }
            else
            {
                cout << "\nUser not found!!\nKindly enter correct user_id/password.\n";
                professorLogin();
            }
        }
    }
    if (found == 0)
    {
        cout << "\nUser not found!!\nKindly enter correct user_id/password.\n";
        professorLogin();
    }

    MyReadFile.close();
}