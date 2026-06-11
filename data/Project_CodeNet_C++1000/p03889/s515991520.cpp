#include<bits/stdc++.h>
using namespace std;
string a;
char b[100003];
int r=1;
int main(){
    cin>>a;
    int f=a.size()-1;
    for(int i=0;i<=f;i++)
       b[f-i]=a[i];
    for(int i=0;i<=f;i++){
        if(b[i]=='b')b[i]='d';
        else if(b[i]=='d')b[i]='b';
        else if(b[i]=='p')b[i]='q';
        else b[i]='p';
        if(b[i]!=a[i]){
           r=0;
           break;
        }
    }
    if(r==0)cout<<"No";
    else cout<<"Yes";
}