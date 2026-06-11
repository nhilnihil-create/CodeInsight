#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC50(void);
void ABC51(void);
void ABC52(void);
void ABC53(void);
void ABC54(void);
void ABC55(void);
void ABC56(void);
void ABC57(void);
void ABC58(void);
void ABC59(void);

int main(void){
    ABC59();
}

void ABC59(){
    int da,db;
    vector<string> a(2);
    cin>>a[0]>>a[1];
    da=a.at(0).length();
    db=a.at(1).length();
    if(da>db)cout<<"GREATER"<<endl;
    else if(da<db)cout<<"LESS"<<endl;
    else if(da=db){
        if(a[0]>a[1])cout<<"GREATER"<<endl;
        else if(a[0]<a[1])cout<<"LESS"<<endl;
        else if(a[0]==a[1])cout<<"EQUAL"<<endl;
    }
}