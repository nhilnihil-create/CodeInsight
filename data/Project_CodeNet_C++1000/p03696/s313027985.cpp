#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    string S; cin>>S;

    int sum=0,val=0,minV=0;
    for(auto c:S){
        if(c=='('){
            val++;
            sum++;
        }else{
            val=max(0,val-1);
            sum--;
        }
        minV=min(minV,sum);
    }

    rep(i,0,-minV) S='('+S;
    rep(i,0,val) S+=')';

    cout<<S<<endl;
}