#include<bits/stdc++.h>
using namespace std;

string s,c;

int main(){
    cin>>s;
    c=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        if(s[i]=='p') s[i]='q';
        else if(s[i]=='q') s[i]='p';
        else if(s[i]=='b') s[i]='d';
        else if(s[i]=='d') s[i]='b';
    }
    if(s==c) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}