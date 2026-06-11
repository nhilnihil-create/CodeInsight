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
    ABC71();
}

void ABC71(void){
    int x,a,b;
    cin>>x>>a>>b;
    if(abs(a-x)<abs(b-x))cout<<'A'<<endl;
    else cout<<'B'<<endl;
}