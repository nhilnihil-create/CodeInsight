#include<bits/stdc++.h>
using namespace std;
string a,b;
int main() {
    cin>>a;
    b=a;
    int j=a.size();
    for(int i=0; i<a.size(); i++)
        a[--j]=b[i];
    for(int i=0; i<a.size(); i++) {
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d') a[i]='b';
        else if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
    }
    if(a==b)
    cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}