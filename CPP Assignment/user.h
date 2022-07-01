#include <bits/stdc++.h>

using namespace std;

class User
{
private:
    string name, id, pass;

public:
    User(string name, string id, string pass)
    {
        this->name = name;
        this->id = id;
        this->pass = pass;
    }
};

class Student : public User
{
private:
    string name, id, pass;
    int role;

public:
    Student(string name, string id, string pass, int role) : User(name, id, pass)
    {
        role = 3;
    }
};

class Professor : public User
{
private:
    string name, id, pass;
    int role;

public:
    Professor(string name, string id, string pass, int role) : User(name, id, pass)
    {
        role = 2;
    }
};

class Librarian : public User
{
private:
    string name, id, pass;
    int role;

public:
    Librarian(string name, string id, string pass, int role) : User(name, id, pass)
    {
        role = 1;
    }
};