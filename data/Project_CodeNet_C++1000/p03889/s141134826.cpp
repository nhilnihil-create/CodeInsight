#include<bits/stdc++.h>
using namespace std;
int main(){

    string st,sd;
    cin>>st;
    sd=st;
    int n;
    n=st.size();
    reverse(st.begin(),st.end());
    if(!n%2){cout<<"No";return 0;}
    for(int i=0;i<n;i++){
        if(st[i]=='b')st[i]='d';
        else if(st[i]=='d')st[i]='b';
        else if(st[i]=='p')st[i]='q';
        else if(st[i]=='q')st[i]='p';
    }
    if(st==sd)cout<<"Yes"; else cout<<"No";
        
    
    return 0;
}