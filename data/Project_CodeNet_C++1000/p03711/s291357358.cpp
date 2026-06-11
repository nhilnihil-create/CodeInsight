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
    ABC62();
}

void ABC62(void){
    int a[6]={1,3,5,7,8,12};
    int b[4]={4,6,9,11};
    int x,y,k=0,d=0,i;
    cin>>x>>y;
    if(x==2)++d;
    if(y==2)++d;
    for(i=0;i<=3;++i){
        if(x==b[i])++k;
        if(y==b[i])++k;
    }
    if((d==0&&k==0)||d==2||k==2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}