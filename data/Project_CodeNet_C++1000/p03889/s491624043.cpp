#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1000001],c[1000001];

int main(){
    int b,num=0,l=0;
    cin>>a;
    b=strlen(a);
    
    for(int i=b-1;i>=0;i--) {
        c[num]=a[i];
        if(c[num]=='b') c[num]='d';
        else if(c[num]=='d') c[num]='b';
        else if(c[num]=='p') c[num]='q';
        else if(c[num]=='q') c[num]='p';
        num++;
    }
    
    for(int i=0;i<=b-1;i++) {
        if(a[i]!=c[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}