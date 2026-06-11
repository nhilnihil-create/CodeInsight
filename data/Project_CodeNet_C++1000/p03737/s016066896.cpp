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
    ABC59();
    return 0;
}

void ABC59(void){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    s1[0]=s1[0]-('a'-'A');
    s2[0]=s2[0]-('a'-'A');
    s3[0]=s3[0]-('a'-'A');
    cout<<s1[0]<<s2[0]<<s3[0]<<endl;
}