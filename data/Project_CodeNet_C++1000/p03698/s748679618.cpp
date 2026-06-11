#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
    string S;
    cin>>S;
    bool c=false;
    sort(S.begin(),S.end());
    int a=S.size();
    rep(i,a){
        if(S[i]==S[i+1]){
            c=true;
        }
    }
    if(c==true){
        cout<<"no"<<endl;
    }
    else
    {
        cout<<"yes"<<endl;
    }
}
