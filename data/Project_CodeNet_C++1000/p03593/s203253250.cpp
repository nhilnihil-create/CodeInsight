#include<iostream>
#include<algorithm>
using namespace std;
int H,W,c[26],d4,d2,d1,t;
char a;
int main(void){
    cin>>H>>W;
    for(int i=0;i<H*W;i++){cin>>a;c[a-'a']++;}
    sort(c,c+26,greater<int>());
    d1=H%2&&W%2;
    d2=(H*(W%2)+W*(H%2)-d1)/2;
    d4=(H*W-d2*2-d1)/4;
    for(int i=0;i<26;i++){
        t=min(d4,c[i]/4);
        d4-=t;
        c[i]-=4*t;
        if(i==25&&d4!=0){cout<<"No"<<endl;return 0;}
    }
    for(int i=0;i<26;i++){
        t=min(d2,c[i]/2);
        d2-=t;
        c[i]-=2*t;
        if(i==25&&d2!=0){cout<<"No"<<endl;return 0;}
    }
    cout<<"Yes"<<endl;
    return 0;
}