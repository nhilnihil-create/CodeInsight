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
    ABC66();
}

void ABC66(void){
    int i,max;
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    max=a[0];
    for(i=1;i<3;++i){
        if(max<a[i])max=a[i];
    }
    cout<<a[0]+a[1]+a[2]-max<<endl;
}