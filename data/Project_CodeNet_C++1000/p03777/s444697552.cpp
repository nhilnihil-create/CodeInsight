#include <iostream>
using namespace std;
void ABC50(void);
void ABC52(void);
void ABC53(void);
void ABC54(void);
void ABC55(void);
void ABC56(void);
void ABC57(void);
void ABC58(void);
void ABC59(void);

int main(void){
    ABC56();
    return 0;
}

void ABC56(void){
    char a,b;
    cin>>a>>b;
    if(a=='H')cout<<b<<endl;
    if(a=='D'&&b=='H'){cout<<'D'<<endl;}
    else if(a=='D')cout<<'H'<<endl;
}