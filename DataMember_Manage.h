#ifndef DATAMEMBER_MANAGE_H
#define DATAMEMBER_MANAGE_H
#include<string.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<process.h>
#include<windows.h>

using namespace std;

HWND console = GetConsoleWindow();
RECT rec;

void gotoxy(int x, int y){
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

void beg(){
    GetWindowRect(console, &rec);
    int y=44,i;
        char yo[]="Nishant And Deepak Presents";
        string r="";
        string a="";
        for(i=26;i>0;i--){
            r+=yo[i];
            for(int b=r.length();b>=0;b--){
                a+=r[b];
            }
            cout<<a;
            Sleep(50);
            system("cls");
            a="";
        }
        for(i=0;i<((rec.right-rec.left-(27*8.17))/8.17);i++){
            gotoxy(i,0);
            cout<<"Nishant And Deepak Presents";
            Sleep(50);
            system("cls");

            GetWindowRect(console, &rec);
        }
        cout<<"i";
        int b=((rec.right-rec.left-(27*8.17))/8.17)-27;
        for(i=26;i>=0;i--){
            for(int b=0;b<i;b++){
                a+=yo[b];
            }
            gotoxy(i+b,0);
            cout<<a;
            Sleep(50);
            system("cls");
            a="";
            b+=2;
        }
}

char* color(int color=7, char* Message = ""){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return Message;
}
string middis(string word){
    GetWindowRect(console, &rec);
    size_t siz=word.length();
    size_t mid=((rec.right-rec.left-(siz*8.17))/8.17)/2;
    string spaces;
    spaces.resize(mid,' ');
    word.insert(0,spaces);
    return word;
}

class DataMember_Manage
{
    private:
        static const int no_of_data_members=20;
        int alpha,whole,deci,dindex[3][no_of_data_members],dusing_n[3][no_of_data_members];
        string data[3][no_of_data_members];
    public:
        int static constexpr Getno_of_data_members()
        {
            return no_of_data_members;
        }
        DataMember_Manage()
        {
            alpha=0;
            whole=0;
            deci=0;
            for(int y=0;y<3;y++)
                {   for(int z=0;z<no_of_data_members;z++)
                    dusing_n[y][z]=0;
                }
            for(int y=0;y<3;y++)
                {   for(int z=0;z<no_of_data_members;z++)
                    dindex[y][z]=-2;
                }
        }
        void initializ_zero()
        {
            alpha=0;
            whole=0;
            deci=0;
        }
        void set_using_zero()
        {
            for(int y=0;y<3;y++)
                {
                    for(int z=0;z<no_of_data_members;z++)
                    dusing_n[y][z]=0;
                }
        }
        void clear_index()
        {
            for(int y=0;y<3;y++)
                {   for(int z=0;z<no_of_data_members;z++)
                    dindex[y][z]=-2;
                }
        }
        int dGetusing_n(int data_type,int postion){
            return dusing_n[data_type][postion];
        }
        void dSetusing_n(int data_type,int postion){
            dusing_n[data_type][postion] = 1;
        }
        int Getdindex(int data_type,int postion){
            return dindex[data_type][postion];
        }
        void Setdindex(int val,int data_type,int postion){
            dindex[data_type][postion] = val;
        }
        void tokdata( string data_f){
          string temdata[no_of_data_members];
          string temp;
          int len=(data_f.length()-1);//to be used later for checking in while loop
          int u=0,e=0,q=0,pos=0;
          if(!(data_f[len]==','))
                {
                    system("cls");
                    cout<<middis(color(4,"Error"))<<endl;
                    cout<<color(2,"No Comma at the end")<<endl;
                    cout<<middis(color(1,"Program will now exit"));
                    exit(1);
                }

        while(pos<len)
        {
            while(1)
                    {
                        if(pos>len)
                        {
                            system("cls");
                            cout<<middis(color(4,"Error"))<<endl;
                            cout<<color(2,"No \'= \'sign in front of data type")<<endl;
                            cout<<middis(color(1,"Program will now exit"));
                            exit(1);
                        }
                        temp=data_f.substr(pos,data_f.find_first_of(",",pos)-pos);
                        pos=data_f.find_first_of(",",pos)+1;
                        u=0,e=0;
                         while(!u&&!e)               //removes space
                                        {   u=temp.compare(temp.length()-1,1," ");
                                            if(!u)
                                            {
                                            size_t found = temp.find_last_of(" ");
                                            temp=temp.substr(0,found);
                                            }
                                            e=temp.compare(0,1," ");
                                            if(!e)
                                            {
                                            size_t found = temp.find_first_of(" ");
                                            temp=temp.substr(found+1);
                                            }

                                        }
                        if(temp.length()==0){
                         cout<<"Input Empty"<<endl;
                         getch();
                         exit(1);
                        }
                        if(!temp.compare(0,1,"="))
                            break;
                        if(no_of_data_members==q)
                        {
                            cout<<middis(color(4,"Error"));
                            exit(0);
                        }
                        temdata[q]=temp;
                        q++;

                    }


                    string temp2=temp.erase(0,1);
                    u=0,e=0;

                                while(!u&&!e)               //removes space
                                        {   u=temp2.compare(temp2.length()-1,1," ");
                                            if(!u)
                                            {
                                            size_t found = temp2.find_last_of(" ");
                                            temp2=temp2.substr(0,found);
                                            }
                                            e=temp2.compare(0,1," ");
                                            if(!e)
                                            {
                                            size_t found = temp2.find_first_of(" ");
                                            temp2=temp2.substr(found+1);
                                            }

                                        }
                    for(int h=0;h<temp2.length();h++)
                    {
                        temp2[h]=tolower(temp2[h]);
                    }
                int o=0;
                if(!temp2.compare("alphabets"))
                {
                    while (o<q)
                        {
                            data[0][alpha+o]=temdata[o];
                            o++;

                        }
                        alpha+=q;
                        q=0;
                }
                else if(!temp2.compare("whole number"))
                {
                    while (o<q)
                        {
                            data[1][whole+o]=temdata[o];
                            o++;

                        }
                        whole+=q;
                        q=0;
                }
                else if(!temp2.compare("decimal"))
                {
                   while (o<q)
                        {
                            data[2][deci+o]=temdata[o];

                            o++;
                        }
                        deci+=q;
                        q=0;
                }
                else
                {

                    system("cls");
                    cout<<middis(color(4,"Error in Input"));

                    exit(1);
                }

        }


}
        int Getalpha()
        {
            return alpha;
        }
        int Getwhole()
        {
            return whole;
        }
        int Getdeci()
        {
            return deci;
        }
        string Getdata(int data_type,int position)
        {
            return data[data_type][position];
        }


};

#endif // DATAMEMBER_MANAGE_H
