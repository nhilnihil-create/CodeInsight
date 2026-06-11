#include <iostream>
using namespace std;
void ABC60(void);
void ABC61(void);
void ABC62(void);
void ABC63(void);
void ABC64(void);
void ABC65(void);
void ABC66(void);
void ABC67(void);
void ABC68(void);
void ABC69(void);

int main(void){
    ABC67();
}

void ABC67(void){
    int a,b;
    cin>>a>>b;
    if(a%3==0||b%3==0||(a+b)%3==0)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}