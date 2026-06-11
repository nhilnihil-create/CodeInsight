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
    ABC60();
}

void ABC60(void){
    string a,b,c;
    int i,j;
    cin >> a >> b >> c;
    for(i=0;a[i]!='\0';++i){}
    for(j=0;b[j]!='\0';++j){}
    if((a[i-1]==b[0])&&(b[j-1]==c[0]))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}