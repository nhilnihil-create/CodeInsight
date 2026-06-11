#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string s; cin>>s;
    int64_t K; cin>>K;

    rep(i,0,s.size()){
        int64_t n='z'-s.at(i)+1; //'a'までに必要な数
        if(n<26 && n<=K){
            s.at(i)='a';
            K-=n;
        }
    }

    K%=26;
    s.back()+=K;
    cout<<s<<endl;
}