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
    ABC54();
    return 0;
}

void ABC54(void){
    int a,b;
    cin>>a>>b;
    if(a==1)a=14;
    if(b==1)b=14;
    if(a>b)cout<<"Alice"<<endl;
    else if(b>a)cout<<"Bob"<<endl;
    else cout<<"Draw"<<endl;
}