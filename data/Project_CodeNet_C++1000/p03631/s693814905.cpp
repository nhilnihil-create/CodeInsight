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
    ABC70();
}

void ABC70(void){
    int n;
    cin>>n;
    if(n/100==n%10)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}