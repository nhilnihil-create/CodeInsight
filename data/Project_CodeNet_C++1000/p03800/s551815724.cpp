#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    string s;
    cin>>n>>s;
    vector<bool>ok(n);
    string t=s;
    rep(f,4){
        f%2==1?t[0]='S':t[0]='W';
        f>=2?t[1]='S':t[1]='W';
        for(int i=1; i<n-1; ++i){
            if(s[i]=='o'){
                if(t[i]=='W'){
                    if(t[i-1]=='S')t[i+1]='W';
                    else t[i+1]='S';
                }
                else{
                    if(t[i-1]=='S')t[i+1]='S';
                    else t[i+1]='W';
                }
            }
            else{
                if(t[i]=='S'){
                    if(t[i-1]=='S')t[i+1]='W';
                    else t[i+1]='S';
                }
                else{
                    if(t[i-1]=='S')t[i+1]='S';
                    else t[i+1]='W';
                }
            }
        }
        bool ng=false;
        for(int i=1; i<=n; ++i){
            if(s[(i%n)]=='o'){
                if(t[(i%n)]=='S'){
                    if(t[(i-1)%n]!=t[(i+1)%n])ng=true;
                }
                else{
                    if(t[(i-1)%n]==t[(i+1)%n])ng=true;
                }
            }
            else{
                if(t[(i%n)]=='W'){
                    if(t[(i-1)%n]!=t[(i+1)%n])ng=true;
                }
                else{
                    if(t[(i-1)%n]==t[(i+1)%n])ng=true;
                }
            }
        }
        if(!ng){cout<<t<<endl; return 0;}
    }
    cout<<-1<<endl;
}