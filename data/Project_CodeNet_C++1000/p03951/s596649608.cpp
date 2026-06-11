#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    int cnt=n;
    for(int i=0; i<n; ++i){
        if(t.substr(0,i+1)==s.substr(n-i-1,i+1))cnt=n-i-1;
    }
    cout<<n+cnt<<endl;
    return 0;
}