#include <iostream>
using namespace std;
void ABC70(void);
void ABC71(void);
void ABC72(void);
void ABC73(void);
void ABC75(void);
void ABC77(void);
void ABC78(void);
void ABC79(void);

int main(void){
    ABC72();
}

void ABC72(void){
    int x,t;
    cin>>x>>t;
    if(x<t)cout<<0<<endl;
    else cout<<x-t<<endl;
}