#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    rep(i,4){
        vector<char> ans(n);
        if(i==0) ans[0]='S',ans[1]='S';
        if(i==1) ans[0]='S',ans[1]='W';
        if(i==2) ans[0]='W',ans[1]='S';
        if(i==3) ans[0]='W',ans[1]='W';
        rep(j,n){
            if(j==0||j==1) continue;
            if(s[j-1]=='o'&&ans[j-1]=='S') ans[j]=ans[j-2];
            if(s[j-1]=='x'&&ans[j-1]=='W') ans[j]=ans[j-2];
            if(s[j-1]=='o'&&ans[j-1]=='W'){
                if(ans[j-2]=='S') ans[j]='W';
                else ans[j]='S';
            }
            if(s[j-1]=='x'&&ans[j-1]=='S'){
                if(ans[j-2]=='S') ans[j]='W';
                else ans[j]='S';
            }
        }
        int x=1;
        if(s[n-1]=='o'&&ans[n-1]=='S'){
            if(ans[n-2]!=ans[0]) x=0;
        }
        if(s[n-1]=='x'&&ans[n-1]=='W'){
            if(ans[n-2]!=ans[0]) x=0;
        }
        if(s[n-1]=='o'&&ans[n-1]=='W'){
            if(ans[n-2]==ans[0]) x=0;
        }
        if(s[n-1]=='x'&&ans[n-1]=='S'){
            if(ans[n-2]==ans[0]) x=0;
        }
        if(s[0]=='o'&&ans[0]=='S'){
            if(ans[n-1]!=ans[1]) x=0;
        }
        if(s[0]=='x'&&ans[0]=='W'){
            if(ans[n-1]!=ans[1]) x=0;
        }
        if(s[0]=='o'&&ans[0]=='W'){
            if(ans[n-1]==ans[1]) x=0;
        }
        if(s[0]=='x'&&ans[0]=='S'){
            if(ans[n-1]==ans[1]) x=0;
        }
        if(x){rep(j,n) cout<<ans[j];return 0;}
    }
    cout<<-1;
}