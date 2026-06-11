#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    int a,z,n=s.size();
    rep(i,n){
        if(s[i]=='Z')z=i;
    }
    for(int i=n-1; i>=0; --i){
        if(s[i]=='A')a=i;
    }
    cout<<z-a+1<<endl;
}
