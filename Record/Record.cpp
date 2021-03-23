#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include "Record.h"
#include <cstdlib>
using namespace std;

abstract :: abstract()
{
    record_name = "0";
    artist_name = "0";
    year_released = "0";
    price = 0;
}

abstract :: abstract (string record, string artist, string year, int p)
{
    record_name = record;
    artist_name = artist;
    year_released = year;
    price = p;
}

string abstract :: get_val1 ()
{
    return record_name;
}

string abstract :: get_val2 ()
{
    return artist_name;
}

string abstract :: get_val3 ()
{
    return year_released;
}

int abstract :: get_val4 ()
{
    return price;
}


record :: record ()
{    }

record :: record (string record, string artist, string year, int p) : abstract (record, artist, year, p)
{    }

void record :: show()
{

}


Price :: Price ()
{
    total_price = 0;
}

void Price :: set_num (int x)
{
    total_price = x;
}

int Price :: get_price ()
{
    return total_price;
}


Price operator + (Price op, int k)
{
    Price temp;

    temp.total_price = op.total_price + k;

    return temp;
}

int findint(string text);

void BUY ()
{
    string str1, str2, str3, sline;
    int y, k = 0, total = 0, in;
    Price ob;
    cout << endl << "Number of Records to Buy : ";
    cin >> y;
    ifstream Music;
    Music.open("music.txt");

    for (int i=0; i<y; i++)
    {
        cout << endl << "Enter Record Name : ";
        cin >> sline;

        //size_t p;
        while(Music.good())
        {
            Music >> str1 >> str2 >> str3 >> in;
            if (sline == str1)
            {
                k++;
                cout << "Record Details :" << endl;
                cout << str1 << ":" << str2 << ";  Released in " << str3 << "  Price : " << in <<" Tk" << endl << endl;

                ob = ob+in;

                break;
            }
        }
        if (k==0)
            cout << "No Records Found" << endl << endl;
    }

    cout << endl << endl << "Total Cost = " << ob.get_price() << " Tk" << endl << endl
    ;
    if (ob.get_price()>=3000)
    {
        int dis = ob.get_price() - (0.1*ob.get_price());
        cout << "Discount Price is : " << dis <<" Tk" << endl << endl;
    }

    Music.close();
}

void ADD ()
{
    fstream music ("music.txt", ios :: in | ios :: out | ios :: app);
    int x,pr,tp=0;
    string n1, n2, n3;
    cout << "Number of Records To Return : ";
    cin >> x;
    record *ob[1000];
    if (music.is_open())
    {
        for (int i=0; i<x; i++)
        {
            char c = getchar();
            cout << "Record Name : ";
            getline(cin, n1);
            cout << "Artist Name : ";
            getline(cin, n2);
            cout << "Year of Release : ";
            getline(cin, n3);
            cout << "Record Price : ";
            cin >> pr;

            ob[i] = new record (n1, n2, n3, pr);
            music << ob[i]->get_val1() << "    " << ob[i]->get_val2() <<
            "    " << ob[i]->get_val3() << "    " << ob[i]->get_val4() << endl;

            tp +=pr;

            cout << endl;

        }
        cout << endl << "Records Added Successfully" << endl;
        cout << "Refund for Returning : " << 0.5*tp << " Tk" << endl << endl;
        music.close();
    }
}

void menu ()
{
    int choice;
    cout << "01. Buy Record" << endl;
    cout << "02. Return Record" << endl;
    cout << "03. Exit" << endl << endl;
    cout << "Enter Option : ";
    cin >> choice;
    cout << endl;

    if (choice == 1)
        BUY();
    else if (choice == 2)
        ADD();
    else if (choice == 3)
    {
        cout << "End of Program" << endl << endl;
        exit(0);
    }
    else
        cout << "Wrong Input, Try Again" << endl << endl;

}
