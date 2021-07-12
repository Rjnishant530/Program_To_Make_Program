#include<stdio.h>
#include<iostream>
#include <string.h>
#include <cstddef>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include "C:\Users\Fictics\Desktop\Program to make a Program\include\DataMember_Manage.h"
#include "C:\Users\Fictics\Desktop\Program to make a Program\include\Function_manage.h"
using namespace std;
Function_manage b1,b9;

int main()
{
    /*ofstream f("function.rar",ios::out|ios::app);

    for(int y=0;y<5;y++){
    b9.prog_input();
    f.write((char *)&b9,sizeof(b9));
    b9.console_output();
    getch();
    system("cls");
    }
    f.close();*/
    ifstream f1("function.rar",ios::in);
    f1.seekg(0);

    while(1){
    f1.read((char *)&b1,sizeof(b1));
        if(f1.eof())
            break;
    b1.console_output();
    cout<<b1.getalphaf();
    cout<<b1.getwholef();
    cout<<b1.getdecif();
    getch();
    system("cls");
    }
    f1.close();
return 0;
}

