#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    string s;
    int k;
    cin>>s>>k;
    int n=s.size();
    rep(i,n-1){
        if(s[i]=='a')continue;
        if(s[i]-'a'+k<26)continue;
        k-=26-(s[i]-'a');
        s[i]='a';
    }
    int x=s[n-1]-'a'+k%26;
    if(x>=26)x-=26;
    s[n-1]=x+'a';
    cout<<s<<endl;
}