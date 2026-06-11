#include<bits/stdc++.h>
using namespace std;
int main(){
    string n,m;
    cin>>n;
    m=n;
    reverse(n.begin(),n.end());
    int c=n.size();
    for(int i=0;i<c;i++){
        if(n[i]=='b')n[i]='d';
        else if(n[i]=='d')n[i]='b';
        else if(n[i]=='p')n[i]='q';
        else if(n[i]=='q')n[i]='p';
    }
    if(n==m)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}