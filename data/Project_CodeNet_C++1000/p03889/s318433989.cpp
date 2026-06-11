#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

string a,b;

inline int read(void){
    int x=0,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-')
            f=-f;
    for(;isdigit(ch);ch=getchar())
        x=(x<<3)+(x<<1)+(ch&15);
    return x*f;
}

int main(void){
    cin>>a;
    b=a;
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();++i){
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d') a[i]='b';
        else if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
    }
    if(a==b) printf("Yes");
    else printf("No");
}