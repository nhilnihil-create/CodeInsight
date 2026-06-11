#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s; int k;
    cin>>s>>k;
    int n=s.size();
    rep(i,n){
        if(26-(s[i]-'a')<=k){if(s[i]!='a')k-=26-(s[i]-'a'); s[i]='a';}
    }
    if(k!=0&&k%26!=0)s[n-1]=(s[n-1]-'a'+k%26)%26+'a';
    cout<<s<<endl;
    return 0;
}