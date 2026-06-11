#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string s;
    cin>>s;

    while(s.find("Z")<s.find("A")) s[s.find("Z")]='F';
    int maxv=0;
    bool flag=true;
    while(flag){
        int n=s.find("Z")-s.find("A")+1;
        maxv=max(maxv,n);
        s[s.find("Z")]='F';
        if(s.find("A")==string::npos) flag=false;
        if(s.find("Z")==string::npos) flag=false;
    }
    cout<<maxv<<"\n";
    return 0;
}