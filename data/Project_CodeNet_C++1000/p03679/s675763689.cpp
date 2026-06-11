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
    ABC65();
}

void ABC65(void){
    int a,b,x;
    cin>>a>>b>>x;
    if(x<=b){cout<<"delicious";}
    else if(x<=b+a){cout<<"safe";}
    else{cout<<"dangerous";}
}