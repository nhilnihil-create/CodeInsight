#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC40(void);
void ABC41(void);
void ABC42(void);
void ABC43(void);
void ABC44(void);
void ABC45(void);
void ABC46(void);
void ABC47(void);
void ABC48(void);
void ABC49(void);

int main(void){
    ABC48();
}

void ABC48(){
    int h,w,i,j;
    cin>>h>>w;
    char s[h][w];
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin>>s[i][j];
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cout<<s[i][j];
        }
        cout<<endl;
        for(j=0;j<w;j++){
            cout<<s[i][j];
        }
        cout<<endl;
    }
}