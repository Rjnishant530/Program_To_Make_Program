#include <iostream>

#include "Function_manage.h"
#include "DataMember_Manage.h"
#include<string.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<process.h>
#include<fstream>
using namespace std;
Function_manage temp_func_man;
DataMember_Manage Variables;
int numberdata;
int Run_number=0;
int main();

class store_vari_func{
public:
    static const int no_of_data_members=Variables.Getno_of_data_members();
    char func_name[20],data_alpha[no_of_data_members][10],data_deci[no_of_data_members][10],data_whole[no_of_data_members][10];
    void store_vari_func_clear(){
            string y="                     ";
              for(int z=0;z<no_of_data_members;z++){
                   y.copy(data_alpha[z],9);
                   data_alpha[z][9]='\0';
                   y.copy(data_deci[z],9);
                   data_deci[z][9]='\0';
                   y.copy(data_whole[z],9);
                   data_whole[z][9]='\0';
                   }
                   y.copy(func_name,19);
                   func_name[19]='\0';

    }
    int index;

};
const char* clear_space(string temp){
int u=0,e=0;
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
    const char *yo=temp.c_str();
    return yo;
}
void displayfuc(){
    ifstream di("function.rar",ios::in);
    di.seekg(0);
    if(!di.is_open())
        cout<<middis(color(4,"Error 20013OP"));         //Error 20013OP
    ofstream di1("temp.rar",ios::out);
    int u=0;
    while(1)
    {
       di.read((char*)&temp_func_man,sizeof(Function_manage));
       if(di.eof())
        break;
        if (Run_number==0){
            temp_func_man.Setusing_n(0);
        }
        if(temp_func_man.Getusing_n()!=5&&Run_number!=0){
            temp_func_man.Setusing_n(0);
        }
       cout<<u<<color(2," ")<<temp_func_man.Getname();
       gotoxy(18,u+1);
       cout<<color(4," :")<<temp_func_man.Getinfo()<<endl;
       temp_func_man.Setindex(u);
       di1.write((char*)&temp_func_man,sizeof(Function_manage));
       u++;
    }
    Run_number++;
    di.close();
    di1.close();
    int k=remove("function.rar");                       //Error 20013RM
    if(k!=0)
        cout<<middis(color(4,"Error 20013RM"));
    k=rename("temp.rar","function.rar");                //Error 20013RE
    if(k!=0)
        cout<<middis(color(4,"Error 20013RE"));
}
int check_fuction(int y){
    ifstream di ("function.rar",ios::in);
    ofstream di1("temp.rar",ios::out);
    di.seekg(0);
    int check=1;
    if(!di.is_open())
        cout<<middis(color(4,"Error 20013OPF"));         //Error 20013OPF
        while(1)
        {
        di.read((char*)&temp_func_man,sizeof(Function_manage));
            if(di.eof())
                break;

            if(temp_func_man.Getindex()==y)
            {
                if(temp_func_man.Getusing_n()==5){
                    return 3;
                }
                check=0;
                temp_func_man.Setusing_n(1);
                numberdata=temp_func_man.getnumber_of_data_members();
            }

        di1.write((char*)&temp_func_man,sizeof(Function_manage));
        }
    di.close();
    di1.close();
    int k=remove("function.rar");                       //Error 20013RMF
    if(k!=0)
        cout<<middis(color(4,"Error 20013RMF"));
    k=rename("temp.rar","function.rar");                //Error 20013REF
    if(k!=0)
        cout<<middis(color(4,"Error 20013REF"));
    return check;
}
int no_of_using_variables(int data_type){
    int h,sum=0,check=0;
                    if((data_type==0&&Variables.Getalpha()!=0))
                    check=Variables.Getalpha();
                    else if(data_type==1&&Variables.Getwhole()!=0)
                    check=Variables.Getwhole();
                    else if(data_type==2&&Variables.Getdeci()!=0)
                    check=Variables.Getdeci();
                    for(int z=0;z<check;z++){
                    h=Variables.dGetusing_n(data_type,z);
                    if(h==1)
                        sum++;
                    }
return sum;
}
boolean check_needed_number(int j){
    int no,sum,check,h;
                    if((j==0&&Variables.Getalpha()!=0)){

                        no=no_of_using_variables(0);
                        sum=temp_func_man.getalphaf();

                    }
                    else if(j==1&&Variables.Getwhole()!=0){

                        no=no_of_using_variables(1);
                        sum=temp_func_man.getwholef();

                    }

                    else if(j==2&&Variables.Getdeci()!=0){

                        no=no_of_using_variables(2);
                        sum=temp_func_man.getdecif();

                    }
        if(sum==no){
            return false;}
        else
            return true;
}
int displayvariables(){
    int u=0,check=0,t=1;
    Variables.clear_index();
    boolean a=false,w=false,d=false;
    ifstream di("function.rar",ios::in);
    di.seekg(0);
    while(!di.eof()){
       di.read((char*)&temp_func_man,sizeof(Function_manage));
       if(di.eof())
            break;
            if(temp_func_man.Getusing_n()==1){          //set is equal to 2 at the end
                if(temp_func_man.getalphaf()!=0){
                    a=true;
                }
                if(temp_func_man.getwholef()!=0){
                    w=true;
                }
                if(temp_func_man.getdecif()!=0){

                    d=true;
                }
                break;
            }
    }
    if(!(a||w||d)){
        cout<<"Error 09f";
                getch();
                exit(1);
    }
    boolean p=true;
    for(int y=0;y<3;y++)
                {
                    if(y==0&&(Variables.Getalpha()-no_of_using_variables(0)!=0)&&a&&check_needed_number(0))
                        {
                            check=Variables.Getalpha();
                            cout<<color(2,"Alphabets : ");
                            p=false;
                        }
                    if(y==1&&(Variables.Getwhole()-no_of_using_variables(1)!=0)&&w&&check_needed_number(1))
                        {
                            check=Variables.Getwhole();
                            cout<<color(2,"Whole Number : ");
                            p=false;
                        }

                    if(y==2&&(Variables.Getdeci()-no_of_using_variables(2)!=0)&&d&&check_needed_number(2))
                        {
                            check=Variables.Getdeci();
                            cout<<color(2,"Decimal : ");
                            p=false;
                        }
                    if(check==0&&y==2&&p)
                    {
                    system("cls");
                    cout<<"You dont have Valid/Enough Variables to Operate This Function"<<endl;
                    cout<<"Retry with Valid Data types for the Function"<<endl;
                    getch();
                    exit(0);
                    }


                    for(int z=0;z<check;z++){
                    gotoxy(16,t);
                    if(Variables.dGetusing_n(y,z)!=1){
                       cout<<u<<" "<<Variables.Getdata(y,z)<<endl;
                        Variables.Setdindex(u,y,z);
                    u++;t++;
                    }
                    }
                    check=0;
                }
    return (0);
}
int check_variable_index(int x){
    int check=0,k;
        for(int y=0;y<3;y++)
                {
                    if((y==0&&Variables.Getalpha()-no_of_using_variables(0)!=0))
                    check=Variables.Getalpha();

                    if(y==1&&Variables.Getwhole()-no_of_using_variables(1)!=0)
                    check=Variables.Getwhole();

                    if(y==2&&Variables.Getdeci()-no_of_using_variables(2)!=0)
                    check=Variables.Getdeci();

                    for(int z=0;z<check;z++){
                    k=Variables.Getdindex(y,z);
                            if(k==x){
                                Variables.dSetusing_n(y,z);
                                    return 0;
                            }

                    }
                    check=0;
                }
        return 1;
}
string cout_fucn(int v){
    if(v==0)
    {
       return " Data " ;
    }
    else if(v==1)
    {
        return " Second Data ";
    }
    else if(v==2){
        return " Third Data ";
    }
    else if(v>2){
            string h;
        h+=" ";
        h+=v;
        h+="th Data ";
        return (h);
    }
    return "Error";
}
void finalwrite(string name){
    string para[100];
    int abc=0;
    string p=name;
    p+=".cpp";
    const char* array123=p.c_str();
    const char* ar1=array123;
    ofstream f(array123,ios::out);
    f<<"#include<fstream>\n#include<iostream>\n#include<conio.h>\n#include<process.h>\n#include<string.h>\nusing namespace std;\n";
    f<<"fstream f;\nint main();\n";
    f<<"class "<<name<<"{\n\t public: \n\t\t";
    if(Variables.Getalpha()!=0)
        f<<"char ";
    for(int i=0;i<Variables.Getalpha();i++){
        f<<Variables.Getdata(0,i);
        if(i==Variables.Getalpha()-1)
            f<<"[40];";
        else   f<<"[40],";
    }
    f<<"\n\t\t";
    if(Variables.Getwhole()!=0)
        f<<"int ";
     for(int i=0;i<Variables.Getwhole();i++){
        f<<Variables.Getdata(1,i);
        if(i==Variables.Getwhole()-1)
            f<<";";
        else  f<<",";
    }
    f<<"\n\t\t";
    if(Variables.Getdeci()!=0)
        f<<"float ";
     for(int i=0;i<Variables.Getdeci();i++){
        f<<Variables.Getdata(2,i);
        if(i==Variables.Getdeci()-1)
            f<<";";
        else    f<<",";
    }
    f<<"\n";
    ifstream fj("using_functions.rar",ios::in);

    fj.seekg(0);

    store_vari_func templ;
    int u;
    while(1){
        fj.read((char *) &templ,sizeof(templ));
        if(fj.eof())
            break;
        ifstream fi("function.rar",ios::in);
        fi.seekg(0);
             while(1){
                        fi.read((char *)&temp_func_man,sizeof(temp_func_man));
                                if(fi.eof()){break;}
                        array123=temp_func_man.Getname().c_str();

                       if(!strcmp(templ.func_name,array123)){
                             f<<"\t\t"<<temp_func_man.Getreturn_data_type()<<" "<<temp_func_man.Getname()<<"(";
                                if(temp_func_man.getalphaf()!=0){
                                            for(u=0;u<temp_func_man.getalphaf();u++){
                                                f<<"string ";
                                                array123=temp_func_man.getdata_alpha(u).c_str();
                                                f<<array123;
                                                para[abc]+="obj.";
                                                para[abc]+=clear_space(templ.data_alpha[u]);
                                                if(u==temp_func_man.getalphaf()-1)
                                                    break;
                                                para[abc]+=",";
                                                f<<",";
                                            }
                                    }
                                if(temp_func_man.getwholef()!=0){
                                    if(temp_func_man.getalphaf()!=0){
                                        para[abc]+=",";
                                        f<<",";
                                    }
                                    for(u=0;u<temp_func_man.getwholef();u++){
                                        f<<"int ";
                                        array123=temp_func_man.getdata_whole(u).c_str();
                                        para[abc]+="obj.";
                                        para[abc]+=clear_space(templ.data_whole[u]);
                                        f<<array123;
                                        if(u==temp_func_man.getwholef()-1)
                                            break;
                                        para[abc]+=",";
                                        f<<",";
                                    }
                                }
                                if(temp_func_man.getdecif()!=0){
                                    if(temp_func_man.getwholef()!=0){
                                        para[abc]+=",";
                                        f<<",";
                                    }
                                    for(int u=0;u<temp_func_man.getdecif();u++){
                                        f<<"float ";
                                        array123=temp_func_man.getdata_deci(u).c_str();
                                        para[abc]+="obj.";
                                        para[abc]+=clear_space(templ.data_deci[u]);
                                        f<<array123;
                                        if(u==temp_func_man.getdecif()-1)
                                            break;
                                        para[abc]+=",";
                                        f<<",";
                                    }
                                }
                        f<<")"<<"//"<<temp_func_man.Getinfo()<<endl;
                        abc++;
                        int i=0;
                        string temp12;
                        while(i<temp_func_man.Getno_lines()){
                                temp12=temp_func_man.getbody(i);
                                array123=temp12.c_str();
                            f<<"\t\t\t\t\t\t\t\t"<<array123<<endl;
                            i++;
                        }

                    }
                    else;
            }
     fi.close();
    }
    fj.close();
    f<<"\n\t\t";
    f<<"void putdata(){\n\t\t\t\tstring h;";
     for(int i=0;i<Variables.Getalpha();i++){
        f<<"\n\t\t\t\tcout<<\"Enter "<<Variables.Getdata(0,i)<< ": \"<<endl;\n";
        f<<"\t\t\t\tgetline(cin,h);";
        f<<"\n\t\t\t\tif(strcmp(h.c_str(),\".\")){strcpy("<<Variables.Getdata(0,i)<<",h.c_str());}";
        }

    for(int i=0;i<Variables.Getwhole();i++){
        f<<"\n\t\t\t\tcout<<\"Enter "<<Variables.Getdata(1,i)<< ": \"<<endl;\n";
        f<<"\t\t\t\tcin>>h;";
        f<<"if(strcmp(h.c_str(),\".\")){"<<Variables.Getdata(1,i)<<"=atoi(h.c_str());}";
    }
    for(int i=0;i<Variables.Getdeci();i++){
        f<<"\n\t\t\t\tcout<<\"Enter "<<Variables.Getdata(2,i)<< ": \"<<endl;\n";
        f<<"\t\t\t\tcin>>h;";
        f<<"if(strcmp(h.c_str(),\".\")){"<<Variables.Getdata(2,i)<<"=atof(h.c_str());}";
    }
    f<<"\n\t}";
    system("cls");
    cout<<"Select a Primary Key"<<endl;
    int t=1,z=0,check=0,pos1;u=0;
    for(int y=0;y<3;y++)
                {
                    if(y==0&&(Variables.Getalpha()!=0))
                        {
                            check=Variables.Getalpha();
                            cout<<color(2,"Alphabets : ");

                        }
                    if(y==1&&(Variables.Getwhole()!=0))
                        {
                            check=Variables.Getwhole();
                            cout<<color(2,"Whole Number : ");

                        }

                    if(y==2&&(Variables.Getdeci()!=0))
                        {
                            check=Variables.Getdeci();
                            cout<<color(2,"Decimal : ");

                        }
                    while(z<check&&check!=0){
                    gotoxy(16,t);
                    cout<<u<<" "<<Variables.Getdata(y,z)<<endl;
                    Variables.Setdindex(u,y,z);
                    u++;t++;z++;
                    }
                    check=0;z=0;
                }
   cout<<"Enter Index Number ";
   int h;
   cin>>h;
   if(h>u){cout<<middis(color(4,"Invalid Input"));getch();h=remove(ar1);exit(h);}
   check=0;
   string pkey;boolean q=true;
   for(int y=0;y<3;y++)
                {
                    if(y==0&&(Variables.Getalpha()!=0))
                        {
                            check=Variables.Getalpha();
                        }
                    if(y==1&&(Variables.Getwhole()!=0))
                        {
                            check=Variables.Getwhole();
                            }

                    if(y==2&&(Variables.Getdeci()!=0))
                        {
                            check=Variables.Getdeci();
                            }
                    while(z<check&&check!=0){
                     if(Variables.Getdindex(y,z)==h){
                       pkey=Variables.Getdata(y,z);
                       pos1=y;
                        q=false;break;
                    }
                    z++;
                    }
                    check=0;z=0;
                    if(!q){break;}
                }
    system("cls");
    cout<<"Select a Data On Whose Basis You Would Search the Record"<<endl;
    t=1,z=0,check=0,u=0;
    int pos3;
    for(int y=0;y<3;y++)
                {
                    if(y==0&&(Variables.Getalpha()!=0))
                        {
                            check=Variables.Getalpha();
                            cout<<color(2,"Alphabets : ");

                        }
                    if(y==1&&(Variables.Getwhole()!=0))
                        {
                            check=Variables.Getwhole();
                            cout<<color(2,"Whole Number : ");

                        }

                    if(y==2&&(Variables.Getdeci()!=0))
                        {
                            check=Variables.Getdeci();
                            cout<<color(2,"Decimal : ");

                        }
                    while(z<check&&check!=0){
                    gotoxy(16,t);
                    cout<<u<<" "<<Variables.Getdata(y,z)<<endl;
                    Variables.Setdindex(u,y,z);
                    u++;t++;z++;
                    }
                    check=0;z=0;
                }
   cout<<"Enter Index Number ";
   cin>>h;
   if(h>u){cout<<middis(color(4,"Invalid Input"));getch();h=remove(ar1);exit(h);}
   check=0;
   string p1key; q=true;
   for(int y=0;y<3;y++)
                {
                    if(y==0&&(Variables.Getalpha()!=0))
                        {
                            check=Variables.Getalpha();
                        }
                    if(y==1&&(Variables.Getwhole()!=0))
                        {
                            check=Variables.Getwhole();
                            }

                    if(y==2&&(Variables.Getdeci()!=0))
                        {
                            check=Variables.Getdeci();
                            }
                    while(z<check&&check!=0){
                     if(Variables.Getdindex(y,z)==h){
                       p1key=Variables.Getdata(y,z);
                       pos3=y;
                        q=false;break;
                    }
                    z++;
                    }
                    check=0;z=0;
                    if(!q){break;}
                }
    system("cls");
    f<<"\n\t\t void dispkey(){";
    if(pos1==0){f<<"puts("<<pkey<<");";}
    else{f<<"cout<<"<<pkey<<";";}
    f<<"}";
    f<<"\n\t\t";
    if(pos3==0){f<<"string ";}
    else if(pos3==1){f<<"int ";}
    else if(pos3==2){f<<"float ";}
    f<<"findpkey(){";
    f<<"return("<<p1key<<");";
    f<<"}";
    f<<"\n\t\t";
    f<<"void getdata(){";
     for(int i=0;i<Variables.Getalpha();i++){
        f<<"\n\t\t\t\tcout<<\""<<Variables.Getdata(0,i)<<" :\";\n\t\t\t\tputs("<<Variables.Getdata(0,i)<<");";
    }
    for(int i=0;i<Variables.Getwhole();i++){
        f<<"\n\t\t\t\tcout<<\""<<Variables.Getdata(1,i)<<" :\"<<"<<Variables.Getdata(1,i)<<"<<endl;";
    }
    for(int i=0;i<Variables.Getdeci();i++){
        f<<"\n\t\t\t\tcout<<\""<<Variables.Getdata(2,i)<<" :\"<<"<<Variables.Getdata(2,i)<<"<<endl;";
    }
    f<<"\n\t}";
    f<<"\n} obj;\n";
    string y=ar1;
    size_t foun=y.find_last_of(".");
    y.substr(0,foun);
    y+=".rar";
    const char *ar2=y.c_str();
    f<<"void display_all(){\n\tcout<<\"Select A Record\"<<endl;\n\tint i=0,id;\nf.open(\""<<ar2<<"\");\n\twhile(!f.eof()){\n\t\t";
    f<<"f.read((char*)&obj,sizeof(obj));\n\t\t";
    f<<"if(f.eof()) break;\n\t\tcout<<i<<\"  \";\n\t\tobj.dispkey();cout<<endl;\n\t\t";
    f<<"i++;";
    f<<"\n\t}\n\t";
    f<<"cout<<\"Enter valid obj id: \";cin>>id;\n\tif(id>i){cout<<\"Invalid Option\";getch();system(\"cls\");main();}\n\ti=0;\n\tf.close();\n\tf.open(\""<<ar2<<"\");";
    f<<"while(i<=id){\n\t\tf.read((char*)&obj,sizeof(obj));\n\t\ti++;";
    f<<"\n}\nf.close();system(\"cls\");\n}\n";

    f<<"void func_call(string fname){\n";
    f<<"if(fname==\"putdata\"){\n obj.putdata();\n f.open(\""<<ar2<<"\",ios::out|ios::app);\n";
    f<<"f.write((char *)&obj,sizeof(obj));\n f.close();\n}\n";
    f<<"else if(fname==\"getdata\"){\n display_all();\n system(\"cls\"); obj.getdata();\ngetch();\n}";
    ifstream a2("using_functions.rar",ios::in);
    a2.seekg(0);
    abc=0;
    while(!a2.eof()){
        a2.read((char*)&templ,sizeof(store_vari_func));
        if(a2.eof()) break;
        f<<"\nelse if(fname==\""<<clear_space(templ.func_name)<<"\"){\n display_all();\n ";
        f<<"obj."<<clear_space(templ.func_name)<<"("<<para[abc]<<");getch();\n}";
        abc++;
    }
    a2.close();
    f<<"\n}";
    f<<"\nstring middis(string word){\n";
    f<<"size_t siz=word.length();\n";
    f<<"size_t mid=(siz%2==0)?(80-siz)/2:(79-siz)/2;\n";
    f<<"string spaces;\n";
    f<<"spaces.resize(mid,' ');\n";
    f<<"word.insert(0,spaces);\n";
    f<<"return word;\n";
    f<<"}\n";
    f<<"int main(){\nwhile(1){\n";
    f<<"cout<<middis(\"Welcome User\")<<endl;\n";
    f<<"cout<<\"What do you want to do :\"<<endl;\n";
    f<<"cout<<\"1. Create New Record\"<<endl;\n";
    f<<"cout<<\"2. Display A Record\"<<endl;\n";
    f<<"cout<<\"3. Find A Record Using Other Data\"<<endl;\n";
    f<<"cout<<\"4. To Modify A Record\"<<endl;\n";
    f<<"cout<<\"5. To Delete A Record\"<<endl;\n";
    ifstream a1("using_functions.rar",ios::in);
    ofstream temp("temp.rar",ios::out);
    a1.seekg(0);
    int w=6;
    while(1){
        a1.read((char*)&templ,sizeof(store_vari_func));
        if(a1.eof())
            break;
        f<<"cout<<\""<<w<<". Call Function "<<clear_space(templ.func_name)<<"\"<<endl;\n";
        templ.index=w;
        temp.write((char*)&templ,sizeof(store_vari_func));
        w++;
    }
    temp.close();
    a1.close();
    int k=remove("using_functions.rar");                       //Error 20013WM
    if(k!=0)
        cout<<middis(color(4,"Error 20013RM"));
    k=rename("temp.rar","using_functions.rar");                //Error 20013WE
    if(k!=0)
        cout<<middis(color(4,"Error 20013RE"));
    f<<"int check;char c;\n";
    f<<"cin>>check;cin.get(c);\n";
    f<<"system(\"cls\");\n";
    f<<"if(check==1){\n\t\tchar y='y';\n\t\twhile(y=='y'||y=='Y'){\n\t\t\tfunc_call(\"putdata\");\n\t\t\tcout<<\"Want to Enter More (y/n)\";\n\t\t\tcin>>y;cin.get(c);\n\t\t\tsystem(\"cls\");\n\t\t\t}\n\t\t}\n";
    f<<"else if(check==2){\n\t\tfunc_call(\"getdata\");\n\t\tsystem(\"cls\");\n\t\t}\n";
    f<<"else if(check==3){\n\t\tcout<<\"Enter "<<p1key<<" value\"<<endl;\n\t\t";
    if(pos3==0){f<<"string h;getline(cin,h);cin.get(c);";}
    else if(pos3==1){f<<"int h;cin>>h;cin.get(c);";}
    else if(pos3==2){f<<"float h;cin>>h;cin.get(c);";}
    f<<"\n\t\tf.open(\""<<ar2<<"\");\n\t\twhile(1){\n\t\t\tf.read((char*)&obj,sizeof(obj));\n\t\t\tif(f.eof())\n\t\t\t\tbreak;\n\t\t\tif(h==obj.findpkey()){\n\t\t\t\tsystem(\"cls\");\n\t\t\t\tcout<<\"Value Found\"<<endl;\n\t\t\t\tobj.getdata();\n\t\t\t\tgetch();\n\t\t\t\tsystem(\"cls\");\n\t\t\t\tmain();\n\t\t\t}\n\t\t}\n\t\tcout<<\"No Value Found\";getch();\n\t\t\t\tsystem(\"cls\");}";
    f<<"\nelse if(check==4){\n\t\tcout<<\"Enter "<<p1key<<" value\"<<endl;\n\t\t";
    if(pos3==0){f<<"string h;getline(cin,h);cin.get(c);";}
    else if(pos3==1){f<<"int h;cin>>h;cin.get(c);";}
    else if(pos3==2){f<<"float h;cin>>h;cin.get(c);";}
    f<<"\n\t\tint yo=0;\n\t\tf.open(\""<<ar2<<"\");\n\t\tofstream di1(\"temp.rar\",ios::out);\n\t\twhile(1){\n\t\t\tf.read((char*)&obj,sizeof(obj));\n\t\t\tif(f.eof())\n\t\t\t\tbreak;\n\t\t\tif(h==obj.findpkey()){\n\t\t\t\tsystem(\"cls\");\n\t\t\t\tcout<<\"Value Found\"<<endl;\n\t\t\t\tcout<<\"Enter \'.\' to Have Previous Value\"<<endl;\n\t\t\t\tobj.putdata();\n\t\t\t\tsystem(\"cls\");\n\t\t\t\tyo=1;\n\t\t\t\t}\n\t\t\tdi1.write((char*)&obj,sizeof(obj));\n\t\t\t}\n\t\tf.close();\n\t\tdi1.close();\n\t\tint k=remove(\""<<ar2<<"\");\n\t\tif(k!=0)\n\t\t\tcout<<middis(\"Error 20013RM\");\n\t\tk=rename(\"temp.rar\",\""<<ar2<<"\");\n\t\tif(k!=0)\n\t\t\tcout<<middis(\"Error 20013RE\");\n\t\tif(yo==0){\n\t\t\tcout<<\"No Value Found\";getch();\n\t\t\t\tsystem(\"cls\");}}";
    f<<"\n";
    f<<"\nelse if(check==5){\n\t\tcout<<\"Enter "<<p1key<<" value\"<<endl;char ch;\n\t\t";
    if(pos3==0){f<<"string h;getline(cin,h);cin.get(c);";}
    else if(pos3==1){f<<"int h;cin>>h;cin.get(c);";}
    else if(pos3==2){f<<"float h;cin>>h;cin.get(c);";}
    f<<"\n\t\tint yo=0;\n\t\tf.open(\""<<ar2<<"\");\n\t\tofstream di1(\"temp.rar\",ios::out);\n\t\twhile(1){\n\t\t\tf.read((char*)&obj,sizeof(obj));\n\t\t\tif(f.eof())\n\t\t\t\tbreak;\n\t\t\tif(h==obj.findpkey()){\n\t\t\t\tsystem(\"cls\");\n\t\t\t\tcout<<\"Record Deleted\"<<endl;\n\t\t\t\tobj.getdata();\n\t\t\t\tgetch();\n\t\t\t\tyo=1;\n\t\t\t\t}\n\t\t\telse{\n\t\t\t\tdi1.write((char*)&obj,sizeof(obj));\n\t\t\t\t}}\n\t\tf.close();di1.close();\n\t\tsystem(\"cls\");\n\t\tint k=remove(\""<<ar2<<"\");\n\t\tif(k!=0)\n\t\t\tcout<<middis(\"Error 20013RM\");\n\t\tk=rename(\"temp.rar\",\""<<ar2<<"\");\n\t\tif(k!=0)\n\t\t\tcout<<middis(\"Error 20013RE\");\n\t\tif(yo==0){\n\t\t\tcout<<\"No Record Found\";getch();\n\t\t\t\tsystem(\"cls\");}}\n";
    a2.open("using_functions.rar",ios::in);
    a2.seekg(0);
     for(int t=6;t<w;t++)
    {
        a2.read((char*)&templ,sizeof(store_vari_func));
        if(a2.eof())break;
        f<<"else if(check=="<<t<<"){\n\t\tfunc_call(\""<<clear_space(templ.func_name)<<"\");\n\t\tsystem(\"cls\");}\n";

    }
    a2.close();
    f<<"\nelse {\ncout<<\"Invalid Options Program will Now Exit\";\ngetch();\nexit(0);\n}\n";
    f<<"}\nreturn 0;\n}";
    f.close();

}
int main(){
    beg();
    cout<<middis(color(1,"Hello User"))<<endl;
    cout<<(color(2,"What Do u Want to Manage ?"))<<endl;
    string prog_name;
    getline(std::cin,prog_name);
    system("cls");
    cout<<middis(color(1,"What Information Do u Want to Manage"));
    cout<<color(4,"\n Example -> name, = alphabets, rollno, = whole number, marks, = decimal,")<<endl;
    string tevdfv="deepak,nishant,=alphabets,rj,gopal,=whole number,prashant,nayan,=decimal,";
    string data_name;
    getline(std::cin,data_name);
    if(data_name=="temp"){
    Variables.tokdata(tevdfv);
    }
    else{
    Variables.tokdata(data_name);
    }
    char check='y';
    system("cls");
    int i,q;
    ofstream usfunc ("using_functions.rar",ios::out);

    while(check=='y'||check=='Y')
    {
        Variables.set_using_zero();
        cout<<middis(color(2,"What Manipulations do u Want to do with your data ?"))<<endl;
        displayfuc();
        cout<<middis("Enter the Function Id u want to include (one at a time) =>")<<endl<<"        ";
        cin>>i;
        if(i<0)
            break;
        q=check_fuction(i);                     //check and set using =1;
        if(q==1){
        system("cls");
        cout<<middis(color(4,"No Such Function Exists "));
        cout<<middis("Try Again");
        getch();
        system("cls");
        continue;
        }
        else if(q==3){
            cout<<"Function already used......try again ";         //change made
            getch();
            system("cls");
            continue;
        }
        system("cls");
        cout<<"Select Data you Want to Manipulate with this Function"<<endl;
        int h=numberdata,m=0;
        while(h>0){
        i=displayvariables();
        if(i){
        system("cls");
        continue;
        }
        cout<<"Enter"<<cout_fucn(m)<<"Variable Index"<<endl;
        m++;
        cin>>i;
        q=check_variable_index(i);
        if(q){
        system("cls");
        cout<<middis(color(4,"No Such Variable Exists "));
        cout<<middis("Try Again");
        getch();
        system("cls");
        continue;
        }
        h--;
        system("cls");
        }
     const char *temp1=(temp_func_man.Getname()).c_str();
     store_vari_func w1;
        w1.store_vari_func_clear();
        strcpy(w1.func_name,temp1);
        int a=0,b=0,c=0,check1;
        for(int n=0;n<3;n++){
           check1=0;
                if(n==0&&temp_func_man.getalphaf()!=0)
                    check1=Variables.Getalpha();
                if(n==1&&temp_func_man.getwholef()!=0)
                    check1=Variables.Getwhole();
                if(n==2&&temp_func_man.getdecif()!=0)
                    check1=Variables.Getdeci();
            for(int r=0;r<check1;r++){
                if(Variables.dGetusing_n(n,r)==1)
                    {
                        temp1=(Variables.Getdata(n,r)).c_str();
                        if(n==0){
                            strcpy(w1.data_alpha[a],temp1);
                            a++;
                        }
                        if(n==1)
                            {
                            strcpy(w1.data_whole[b],temp1);
                            b++;
                        }
                        if(n==2)
                            {
                            strcpy(w1.data_deci[c],temp1);
                           c++;
                        }
                    }
            }
        }
        usfunc.write((char *)&w1,sizeof(w1));
        system("cls");
        cout<<"Do you Want to Add Another Function?(y/n)"<<endl;
        cin>>check;
        system("cls");
        ifstream di("function.rar",ios::in);
        di.seekg(0);
        if(!di.is_open())
        cout<<middis(color(4,"Error 200134SDG"));         //Error 200134SDG
    ofstream di1("temp.rar",ios::out);

    while(1)
    {
       di.read((char*)&temp_func_man,sizeof(Function_manage));
       if(di.eof())
        break;
        if(temp_func_man.Getusing_n()==1){
            temp_func_man.Setusing_n(5);
        }
              di1.write((char*)&temp_func_man,sizeof(Function_manage));
    }
    di.close();
    di1.close();
    int k=remove("function.rar");                       //Error 20013RDM
    if(k!=0)
        cout<<middis(color(4,"Error 20013RDM"));
    k=rename("temp.rar","function.rar");                //Error 20013RDE
    if(k!=0)
        cout<<middis(color(4,"Error 20013RDE"));

    }
    usfunc.close();
    finalwrite(prog_name);
    return 0;
}
