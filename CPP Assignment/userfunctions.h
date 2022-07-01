#include <bits/stdc++.h>

using namespace std;

void addUser()
{
    string Name, id, pass, role;
    int lib_choice;

    cout << "\nType 1 to add Librarian." << endl;
    cout << "Type 2 to add Professor." << endl;
    cout << "Type 3 to add Student." << endl;

    cout << "\nEnter your choice: ";
    cin >> lib_choice;

    switch (lib_choice)
    {
    case 1:
        role = "librarian";
        break;

    case 2:
        role = "professor";
        break;
    case 3:
        role = "student";
        break;

    default:
        cout << "\nPlease enter a valid choice!\n";
        addUser();
        break;
    }

    cout << "\nEnter Name of user: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Enter user_id of user: ";
    cin >> id;
    cout << "Enter password of user: ";
    cin >> pass;

    ofstream MyFile("userList.txt", ios::app);

    MyFile << Name << "," << id << "," << pass << "," << role << endl;
    cout << "\nUser added successfully!\n";

    MyFile.close();
}

void update_userfile(string newdat, const char *file_name, int n, vector<string> row, int i)
{
    ifstream is(file_name);

    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char c;
    int line_no = 1;
    int j = 0;
    int set = 0;
    while (is.get(c))
    {
        if (c == '\n')
            line_no++;

        if (line_no != n)
            ofs << c;
        else if (line_no == n)
        {
            if (c == ',')
                j++;
            if (j != i)
                ofs << c;
            else if (j == i && set == 0)
            {
                if (i == 0)
                    ofs << "\n";
                else
                    ofs << ",";
                ofs << newdat;
                set = 1;
            }
        }
    }

    ofs.close();

    is.close();

    remove(file_name);

    rename("temp.txt", file_name);
}

void update_user()
{
    string name;
    cout << "\nEnter the user_id of the user you want to update: ";
    cin >> name;

    string rowText;

    ifstream MyReadFile("userList.txt");
    string word;
    vector<string> row;
    int found = 0;
    int line = 0;

    while (getline(MyReadFile, rowText))
    {
        stringstream str(rowText);
        row.clear();
        while (getline(str, word, ','))
        {
            row.push_back(word);
        }
        line++;

        if (row[1] == name)
        {
            MyReadFile.close();
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        cout << "\nType 1 to update Name of the user." << endl;
        cout << "Type 2 to update the user_id of the user." << endl;
        cout << "Type 3 to update the password of the user." << endl;
        cout << "Type 4 to update the role of the user." << endl;

        cout << "\nPlease enter your choice: ";
        int choice;
        cin >> choice;

        string rowText;

        ifstream MyReadFile("userList.txt");
        string word;
        vector<string> row;
        int found = 0;
        int line = 0;

        while (getline(MyReadFile, rowText))
        {
            stringstream str(rowText);
            row.clear();
            while (getline(str, word, ','))
            {
                row.push_back(word);
            }
            line++;

            if (row[1] == name)
            {
                MyReadFile.close();
                found = 1;
                string temp;
                int t;
                switch (choice)
                {
                case 1:
                    cout << "\nCurrent Name of the user is: " << row[0] << endl;
                    cout << "Please update the Name of the user: ";
                    cin.ignore();
                    getline(cin, temp);
                    update_bookfile(temp, "userList.txt", line, row, 0);
                    cout << "\nName updated successfully!!\n";
                    break;

                case 2:
                    cout << "\nCurrent user_id of the user is: " << row[1] << endl;
                    cout << "Please update the user_id of the user: ";
                    cin >> temp;
                    update_bookfile(temp, "userList.txt", line, row, 1);
                    cout << "\nuser_id updated successfully!!\n";
                    break;

                case 3:
                    cout << "\nCurrent password of the user is: " << row[2] << endl;
                    cout << "Please update the password of the user: ";
                    cin >> temp;
                    update_bookfile(temp, "userList.txt", line, row, 2);
                    cout << "\nPassword updated successfully!!\n";
                    break;

                case 4:
                    cout << "\nCurrent role of the user is: " << row[3] << endl;
                    cout << "Please update role(student/professor/librarian) of the user(Kindly write the role in lowercase only): ";
                    cin >> temp;
                    update_bookfile(temp, "userList.txt", line, row, 3);
                    cout << "\nRole updated successfully!!\n";
                    break;

                default:
                    cout << "\nPlease enter a valid choice!\n";
                    update_user();
                    break;
                }

                break;
            }
        }
    }

    else if (found == 0)
    {
        MyReadFile.close();
        cout << "\nUser not found!!\nKindly enter the correct user_id\n";
        update_user();
    }
}

void delete_lineuser(const char *file_name, int n)
{
    ifstream is(file_name);

    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char c;
    int line_no = 1;
    while (is.get(c))
    {
        if (c == '\n')
            line_no++;

        if (line_no != n)
            ofs << c;
    }

    ofs.close();

    is.close();

    remove(file_name);

    rename("temp.txt", file_name);
}

void deleteUser()
{
    string id;
    cout << "\nEnter the user_id of the user you want to delete: ";
    cin >> id;

    string rowText;

    ifstream MyReadFile("userList.txt");
    string word;
    vector<string> row;
    int found = 0;
    int line = 0;

    while (getline(MyReadFile, rowText))
    {
        stringstream str(rowText);
        row.clear();
        while (getline(str, word, ','))
        {
            row.push_back(word);
        }
        line++;

        if (row[1] == id)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        MyReadFile.close();
        delete_lineuser("userList.txt", line);
        cout << "\nDeleted user sucessfully!!\n";
    }
    else if (found == 0)
    {
        MyReadFile.close();
        cout << "\nUser not found!\nKindly enter the correct user_id!\n";
        deleteUser();
    }
}

void listUsers()
{
    string rowText;

    ifstream MyReadFile("userList.txt");
    string word;
    vector<string> row;
    cout << "\nList of all the users: \n";
    cout << "\n";

    while (getline(MyReadFile, rowText))
    {
        stringstream str(rowText);
        row.clear();
        while (getline(str, word, ','))
        {
            row.push_back(word);
        }
        cout << "Name: " << row[0] << endl;
        cout << "user_id: " << row[1] << endl;
        cout << "Role: " << row[3] << endl;
        cout << "\n";
    }
    MyReadFile.close();
}
