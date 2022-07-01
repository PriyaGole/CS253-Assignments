#include <bits/stdc++.h>

using namespace std;

void listbooks()
{
    string rowText;

    ifstream MyReadFile("bookList.txt");
    string word;
    vector<string> row;
    cout << "\nList of all the books: \n";
    cout << "\n";

    while (getline(MyReadFile, rowText))
    {
        stringstream str(rowText);
        row.clear();
        while (getline(str, word, ','))
        {
            row.push_back(word);
        }
        cout << "Title: " << row[0] << endl;
        cout << "Author: " << row[1] << endl;
        cout << "ISBN: " << row[2] << endl;
        cout << "Publication: " << row[3] << endl;
        cout << "\n";
    }
    MyReadFile.close();
}

void bookissued()
{
    string book;
    cout << "\nEnter the name of the book: ";
    cin.ignore();
    getline(cin, book);

    string rowText;

    ifstream MyReadFile("bookList.txt");
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
        if (row[0] == book)
        {
            found = 1;

            if (row[4] == "not_issued")
                cout << "\nThe book is not issued." << endl;
            else
            {
                cout << "\nThe book is issed by: " << row[4] << endl;
                cout << "Role of the user: " << row[5] << endl;
            }

            MyReadFile.close();
            break;
        }
    }
    if (found == 0)
    {
        MyReadFile.close();
        cout << "\nBook not found!!\nKindly enter correct book name.\n";
        bookissued();
    }
}

void userissued_books()
{
    string user;
    cout << "\nEnter the user_id of the user to see the list of books he/she has issued: ";
    cin >> user;

    string rowText;

    ifstream MyReadFile("bookList.txt");
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
        if (row[4] == user)
        {
            if (found == 0)
                cout << "\nBook(s) issued are as follows:" << endl;
            found = 1;
            cout << row[0] << endl;
        }
    }
    if (found == 0)
        cout << "\nNo books issued by the user." << endl;

    MyReadFile.close();
}

void userissued(string user)
{
    string rowText;

    ifstream MyReadFile("bookList.txt");
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
        if (row[4] == user)
        {
            if (found == 0)
                cout << "\nBook(s) issued are as follows:" << endl;
            found = 1;
            cout << row[0] << endl;
        }
    }
    if (found == 0)
        cout << "\nNo books issued." << endl;

    MyReadFile.close();
}

void checkavailability()
{
    string book;
    cout << "\nPlease enter the name of the book to check its availability: ";
    cin.ignore();
    getline(cin, book);
    string rowText;

    ifstream MyReadFile("bookList.txt");
    string word;
    vector<string> row;
    int issue = 1;
    int found = 0;

    while (getline(MyReadFile, rowText))
    {
        stringstream str(rowText);
        row.clear();
        while (getline(str, word, ','))
        {
            row.push_back(word);
        }
        if (row[0] == book)
        {
            found = 1;
            if (row[4] == "not_issued")
            {
                issue = 0;
                cout << "\nBook not issued by anyone!!" << endl;
            }
            break;
        }
    }
    MyReadFile.close();
    if (issue == 1 && found == 1)
    {
        cout << "\nBook already issued by another user." << endl;
    }
    if (found == 0)
    {
        cout << "\nBook not found!!\nKindly enter correct book name.\n";
        checkavailability();
    }
}

void addbook()
{
    string title, author, ISBN, publication;
    cout << "\nEnter the name of the book: ";
    cin.ignore();
    getline(cin, title);

    cout << "Enter the author of the book: ";
    // cin.ignore();
    getline(cin, author);

    cout << "Enter the ISBN of the book: ";
    cin >> ISBN;

    cout << "Enter the publication of the book: ";
    cin.ignore();
    getline(cin, publication);

    ofstream MyFile("bookList.txt", ios::app);

    MyFile << title << "," << author << "," << ISBN << "," << publication << ",not_issued,NA,NA" << endl;

    cout << "\nBook added successfully!!\n";

    MyFile.close();
}

void delete_linebook(const char *file_name, int n)
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

void update_bookfile(string newdat, const char *file_name, int n, vector<string> row, int i)
{
    ifstream is(file_name);

    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char c;
    int line_num = 1;
    int j = 0;
    int s = 0;
    while (is.get(c))
    {
        if (c == '\n')
            line_num++;

        if (line_num != n)
            ofs << c;
        else if (line_num == n)
        {
            if (c == ',')
                j++;
            if (j != i)
                ofs << c;
            else if (j == i && s == 0)
            {
                if (i == 0)
                    ofs << "\n";
                else
                    ofs << ",";
                ofs << newdat;
                s = 1;
            }
        }
    }

    ofs.close();

    is.close();

    remove(file_name);

    rename("temp.txt", file_name);
}

void deletebook()
{
    string name;
    cout << "\nEnter the name of the book you want to delete: ";
    cin.ignore();
    getline(cin, name);

    string rowText;

    ifstream MyReadFile("bookList.txt");
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

        if (row[0] == name)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        MyReadFile.close();
        delete_linebook("bookList.txt", line);
    }
    else if (found == 0)
    {
        cout << "\nBook not found!\nKindly enter correct book name.\n";
        MyReadFile.close();
        deletebook();
    }
}

void updatebook()
{
    string name;
    cout << "\nEnter the name of the book you want to update: ";
    cin.ignore();
    getline(cin, name);

    string rowText;

    ifstream MyReadFile("bookList.txt");
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

        if (row[0] == name)
        {
            MyReadFile.close();
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        cout << "\nType 1 to change the author of the book." << endl;
        cout << "Type 2 to change the ISBN of the book." << endl;
        cout << "Type 3 to change the publication of the book." << endl;

        cout << "\nPlease enter your choice: ";
        int choice;
        cin >> choice;

        string rowText;

        ifstream MyReadFile("bookList.txt");
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

            if (row[0] == name)
            {
                MyReadFile.close();
                found = 1;
                string temp;
                int t;
                switch (choice)
                {
                case 1:
                    cout << "\nCurrent author of the book is: " << row[1] << endl;
                    cout << "Please update the author of the book: ";
                    cin.ignore();
                    getline(cin, temp);
                    update_bookfile(temp, "bookList.txt", line, row, 1);
                    cout << "\nAuthor updated successfully!!\n";
                    break;

                case 2:
                    cout << "\nCurrent ISBN of the book is: " << row[2] << endl;
                    cout << "Please update the ISBN of the book: ";
                    cin >> temp;
                    update_bookfile(temp, "bookList.txt", line, row, 2);
                    cout << "\nISBN updated successfully!!\n";
                    break;

                case 3:
                    cout << "\nCurrent publication of the book is: " << row[3] << endl;
                    cout << "Please update the publication of the book: ";
                    cin.ignore();
                    getline(cin, temp);
                    update_bookfile(temp, "bookList.txt", line, row, 3);
                    cout << "\nPublication updated successfully!!\n";
                    break;

                default:
                    cout << "\nPlease enter a valid choice!\n";
                    updatebook();
                    break;
                }

                break;
            }
        }
    }

    else if (found == 0)
    {
        MyReadFile.close();
        cout << "\nBook not found!!\nKindly enter the correct book name\n";
        updatebook();
    }
}

void issuebook(string user_id, int n)
{
    int count = 0;
    if (n == 3)
    {
        string rowText;

        ifstream MyReadFile("bookList.txt");
        string word;
        vector<string> row;

        while (getline(MyReadFile, rowText))
        {
            stringstream str(rowText);
            row.clear();
            while (getline(str, word, ','))
            {
                row.push_back(word);
            }
            if (row[4] == user_id)
                count++;
        }
        MyReadFile.close();
    }

    if (count > 4)
    {
        cout << "\nCannot issue more than 5 books!!\n";
    }
    else
    {
        cout << "\nType the name of the book you want to issue: ";
        string name;
        cin.ignore();
        getline(cin, name);

        string rowText;

        ifstream MyReadFile("bookList.txt");
        string word;
        vector<string> row;
        int found = 0;
        int line = 0;

        const int MAXLEN = 80;
        char s[MAXLEN];
        time_t t = time(0);
        strftime(s, MAXLEN, "%d/%m/%Y", localtime(&t));

        while (getline(MyReadFile, rowText))
        {
            stringstream str(rowText);
            row.clear();
            while (getline(str, word, ','))
            {
                row.push_back(word);
            }
            line++;

            if (row[0] == name)
            {
                MyReadFile.close();
                found = 1;
                if (row[4] == "not_issued")
                {
                    update_bookfile(user_id, "bookList.txt", line, row, 4);
                    update_bookfile(s, "bookList.txt", line, row, 6);
                    if (n == 2)
                        update_bookfile("professor", "bookList.txt", line, row, 5);
                    else if (n == 3)
                        update_bookfile("student", "bookList.txt", line, row, 5);

                    cout << "\nBook issued successfully!!\n";
                    break;
                }
                else
                    cout << "\nCannot issue the book.\nAlready issued by another user.\n";
            }
        }
        if (found == 0)
        {
            MyReadFile.close();
            cout << "\nBook not available in the library.\n";
        }
        // MyReadFile.close();
    }
}

const int monthDay[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int LeapYear(vector<int> d)
{
    int year = d[2];
    if (d[1] <= 2)
        year--;
    return ((year / 4) - (year / 100) + (year / 400));
}

int NoOfDays(vector<int> date1, vector<int> date2)
{
    long int dayCount1 = (date1[2] * 365);
    dayCount1 += monthDay[date1[1]];
    dayCount1 += date1[0];
    dayCount1 += LeapYear(date1);
    long int dayCount2 = (date2[2] * 365);
    dayCount2 += monthDay[date2[1]];
    dayCount2 += date2[0];
    dayCount2 += LeapYear(date2);
    return (abs(dayCount1 - dayCount2));
}

void displayfine(string user_id, int n)
{
    string rowText;

    ifstream MyReadFile("bookList.txt");
    string word;
    vector<string> row;
    int sum = 0;

    while (getline(MyReadFile, rowText))
    {
        stringstream str(rowText);
        row.clear();
        while (getline(str, word, ','))
        {
            row.push_back(word);
        }

        if (row[4] == user_id)
        {

            const int MAXLEN = 80;
            char s[MAXLEN];
            time_t t = time(0);
            strftime(s, MAXLEN, "%d/%m/%Y", localtime(&t));

            string d;
            vector<int> issue_date;
            stringstream dateissue(row[6]);
            while (getline(dateissue, d, '/'))
            {
                issue_date.push_back(stoi(d));
            }

            vector<int> current_date;
            stringstream datecurrent(s);
            while (getline(datecurrent, d, '/'))
            {
                current_date.push_back(stoi(d));
            }
            int days = NoOfDays(current_date, issue_date);

            if (n == 2)
            {
                if (days > 60)
                    sum = sum + (days - 60) * 5;
            }
            else if (n == 3)
            {
                if (days > 30)
                    sum = sum + (days - 30) * 2;
            }
        }
    }
    MyReadFile.close();
    cout << "\nAmount of fine: Rs. " << sum << endl;
}

void returnbook(string user_id, int n)
{
    cout << "\nType the name of the book you want to return: ";
    string name;
    cin.ignore();
    getline(cin, name);

    string rowText;

    ifstream MyReadFile("bookList.txt");
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

        if (row[0] == name)
        {
            MyReadFile.close();
            found = 1;
            if (row[4] == user_id)
            {
                displayfine(user_id, n);
                update_bookfile("not_issued", "bookList.txt", line, row, 4);
                update_bookfile("NA", "bookList.txt", line, row, 6);
                update_bookfile("NA", "bookList.txt", line, row, 5);

                cout << "\nKindly clear all the dues.\n";
            }
            else
            {
                cout << "\nThis book is not issued by you.\n";
            }
            break;
        }
    }
    if (found == 0)
    {
        MyReadFile.close();
        cout << "\nBook not found.\nKindly enter the correct book name.\n";
        returnbook(user_id, n);
    }
    MyReadFile.close();
}

vector<int> take_int(string str)
{
    stringstream ss(str);
    vector<int> result;
    char ch;
    int tmp;
    while (ss >> tmp)
    {
        result.push_back(tmp);
        ss >> ch;
    }
    return result;
}

bool Leap(int y)
{
    if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0)
        return true;

    return false;
}

int offsetDays(int d, int m, int y)
{
    int off = d;

    switch (m - 1)
    {
    case 11:
        off += 30;
    case 10:
        off += 31;
    case 9:
        off += 30;
    case 8:
        off += 31;
    case 7:
        off += 31;
    case 6:
        off += 30;
    case 5:
        off += 31;
    case 4:
        off += 30;
    case 3:
        off += 31;
    case 2:
        off += 28;
    case 1:
        off += 31;
    }

    if (Leap(y) && m > 2)
        off += 1;

    return off;
}

void revoffsetDays(int offset, int y, int *d, int *m)
{
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (Leap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    *d = offset;
    *m = i;
}

void addDays(int d1, int m1, int y1, int x, string s)
{
    int offset1 = offsetDays(d1, m1, y1);
    int remDays = Leap(y1) ? (366 - offset1) : (365 - offset1);

    int y2, offset2;
    if (x <= remDays)
    {
        y2 = y1;
        offset2 = offset1 + x;
    }

    else
    {
        x -= remDays;
        y2 = y1 + 1;
        int y2days = Leap(y2) ? 366 : 365;
        while (x >= y2days)
        {
            x -= y2days;
            y2++;
            y2days = Leap(y2) ? 366 : 365;
        }
        offset2 = x;
    }

    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);

    cout << "For the book " << s << ", the due date is: " << d2 << "/" << m2 << "/" << y2 << endl;
}

void display_due_date(string user_id, int n)
{
    string name;
    string rowText;

    ifstream MyReadFile("bookList.txt");
    string word;
    vector<string> row;
    int found = 0;
    cout << "\n";

    while (getline(MyReadFile, rowText))
    {
        stringstream str(rowText);
        row.clear();
        while (getline(str, word, ','))
        {
            row.push_back(word);
        }

        if (row[4] == user_id)
        {
            found = 1;

            string d;
            vector<int> issue_date;
            stringstream dateissue(row[6]);
            while (getline(dateissue, d, '/'))
            {
                issue_date.push_back(stoi(d));
            }

            if (n == 2)
                addDays(issue_date[0], issue_date[1], issue_date[2], 60, row[0]);

            if (n == 3)
                addDays(issue_date[0], issue_date[1], issue_date[2], 30, row[0]);
        }
    }
}
