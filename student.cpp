#include <iostream>
#include <fstream>
using namespace std;
class student
{
    int rollno;
    char name[20];
    char div[20];
    char address[40];

public:
    void setData()
    {
        cout << "Enter roll no : ";
        cin >> rollno;
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter Division : ";
        cin >> div;
        cout << "Enter Address: ";
        cin.ignore();
        cin.get(address, 40);
    }
    void showData()
    {
        cout << "Roll No: " << rollno << endl;
        cout << "Name : " << name << endl;
        cout << "Division : " << div << endl;
        cout << "Address : " << address << endl;
    }
    int retrollno()
    {
        return rollno;
    }
};

void write_record()
{
    ofstream of;
    of.open("atharva.dat", ios ::app);
    student obj;
    obj.setData();
    of.write((char *)&obj, sizeof(obj));
    of.close();
}
void display()
{
    ifstream iffile;
    iffile.open("atharva.dat", ios ::binary);
    student obj;
    while (iffile.get((char *)&obj, sizeof(obj)))
    {
        obj.showData();
    }
    iffile.close();
}
void search(int n)
{
    ifstream iffile;
    int flag = 0;
    iffile.open("atharva.dat", ios ::binary);
    student obj;
    while (iffile.get((char *)&obj, sizeof(obj)))
    {
        if (obj.retrollno() == n)
        {
            obj.showData();
            flag = 1;
            break;
        }
    }
     iffile.close();
    if (flag == 0)
    {
        cout << "Data not present"<<endl;
    }
   
}
void del(int n)
{
    ifstream iffile;
    int flag = 0;
    ofstream of;
    iffile.open("atharva.dat", ios ::app);
    of.open("temp.dat", ios ::binary);
    student obj;
    while (iffile.get((char *)&obj, sizeof(obj)))
    {
        if (obj.retrollno() != n)
        {
            of.write((char *)&obj, sizeof(obj));
            flag = 1;
            break;
        }
        iffile.close();
        of.close();
    }
    if (flag == 0)
    {
        cout << "Record not found" << endl;
    }
    cout << "Record Deleted" << endl;
    remove("atharva.dat");
    rename("atharva.dat", "temp.dat");
}
int main()
{
    int n;
    char ch;
    do
    {
        cout << "===========Student Record==========" << endl;
        cout << "1.Write Record" << endl;
        cout << "2.Display" << endl;
        cout << "3.Search" << endl;
        cout << "4.Delete Record" << endl;

        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            write_record();
            break;

        case '2':
            display();
            break;

        case '3':
            cout << "Enter roll no to search" << endl;
            cin >> n;
            search(n);
            break;
        case '4':
            cout << "Enter roll no to delete" << endl;
            cin >> n;
            del(n);
            break;
        case '0':
            exit(0);
        }
    } while (ch != 0);
    return 0;
}
