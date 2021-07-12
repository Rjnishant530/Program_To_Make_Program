#ifndef FUNCTION_MANAGE_H
#define FUNCTION_MANAGE_H
#include "DataMember_Manage.h"
#include<string.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<process.h>
using namespace std;
DataMember_Manage b;
class Function_manage
{

     private:
        int alphaf,wholef,decif;
        int no_lines;
        int using_n;
        int index;
        static const int no_of_data_members=b.Getno_of_data_members();
        char data_alpha[no_of_data_members][10],data_deci[no_of_data_members][10],data_whole[no_of_data_members][10],body[20][30];
        char return_data_type[15],name[20],info[40];

    public:
        Function_manage(){
            alphaf=0;
            wholef=0;
            decif=0;
            using_n=0;
        }
         string getbody(int u){
            return body[u];
        }
        string getdata_alpha(int u){
            return data_alpha[u];
        }
        string getdata_deci(int u){
            return data_deci[u];
        }
        string getdata_whole(int u){
            return data_whole[u];
        }
        int getnumber_of_data_members(){
        return alphaf+wholef+decif;
        }
        int getalphaf(){
            return alphaf;
        }

         int getwholef(){
            return wholef;
        }

         int getdecif(){
            return decif;
        }

        int Getno_lines(){
            return no_lines;
        }
        void Setno_lines(int val){
            no_lines = val;
        }
        int Getusing_n(){
            return using_n;
        }
        void Setusing_n(int val){
            using_n = val;
        }
        int Getindex(){
            return index;
        }
        void Setindex(int val){
            index = val;
        }
        string Getreturn_data_type(){
            return return_data_type;
        }
        string Getname(){
            return name;
        }
        string Getinfo(){
            return info;
        }
        void prog_input(){
            b.initializ_zero();
            cout<<"Enter name of Func"<<endl;
            gets(name);
            cout<<"Enter Information about the function"<<endl;
            gets(info);
            cout<<"Enter Return Type"<<endl;
            gets(return_data_type);
            cout<<"Enter data members"<<endl;
            string dat;
            getline(std::cin,dat);
            b.tokdata(dat);
            alphaf=b.Getalpha();
            decif=b.Getdeci();
            wholef=b.Getwhole();

            int check=0;
            const char *array1;
            int z=0;
            for(int y=0;y<3;y++)
                {   if(y==0&&alphaf!=0)
                    check=alphaf;
                    else if(y==1&&wholef!=0)
                    check=wholef;
                    else if(y==2&&decif!=0)
                    check=decif;
                    else;
                    z=0;
                   while(check>0)
                    {
                      array1 = (b.Getdata(y,z)).c_str();
                      if(y==0){
                        strcpy(data_alpha[z],array1);
                        }

                      if(y==1){
                        strcpy(data_whole[z],array1);
                      }

                      if(y==2){
                        strcpy(data_deci[z],array1);
                        }
                    check--;
                    z++;

                    }

                }

            system("cls");
            cout<<"Enter Func Body"<<endl;
            int r=0;
            strcpy(body[0],"{");
                    while(strcmp(body[r],"no"))
                    {
                       r++;
                       gets(body[r]);

                    }
            no_lines=r+1;
            strcpy(body[r],"}");
        }
         void console_output(){
            int u;
            cout<<return_data_type<<" "<<name<<"(";
            if(alphaf!=0)
            {

                for(u=0;u<alphaf;u++)
                {
                    cout<<"string ";
                    cout<<data_alpha[u];
                    if(u==alphaf-1)
                        break;
                    cout<<",";
                }
            }
            if(wholef!=0)
            {

                for(u=0;u<wholef;u++)
                {
                    cout<<"int ";
                    cout<<data_whole[u];
                    if(u==wholef-1)
                        break;
                    cout<<",";
                }
            }
            if(decif!=0)
            {

                for(u=0;u<decif;u++)
                {
                    cout<<"float ";
                    cout<<data_deci[u];
                    if(u==decif-1)
                        break;
                    cout<<",";
                }
             }
            cout<<")"<<"\\\\"<<info<<endl;
            u=0;
            while(u<no_lines)
            {
                cout<<body[u]<<endl;
                u++;
            }


        }
        void console_output_user(){
            cout<<name<<" "<<info;
        }



};

#endif // FUNCTION_MANAGE_H
