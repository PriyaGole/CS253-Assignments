#include <bits/stdc++.h>
#include "student.h"
#include "librarian.h"
#include "professor.h"

using namespace std;

void selectUser()
{
    int choice;

    cout << "\nType 1 to login as Librarian." << endl;
    cout << "Type 2 to login as Professor." << endl;
    cout << "Type 3 to login as Student." << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        librarianLogin();
        break;
    case 2:
        professorLogin();
        break;
    case 3:
        studentLogin();
        break;
    default:
        cout << "\nKindly enter a valid choice.\n";
        break;
    }
    selectUser();
}
int main()
{
    while (true)
    {
        selectUser();
    }
    return 0;
}