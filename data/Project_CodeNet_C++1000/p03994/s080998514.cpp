#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    string s;
    int k;
    cin>>s>>k;
    
    int n=s.size();
    vector<int> v(n);
    rep(i,n){
        v[i]=s[i]-'a';
    }
    rep(i,n){
        if(v[i]==0) continue;
        if(v[i]+k>=26){
            k-=26-v[i];
            v[i]=0;
        }
    }
    //cout<<k<<endl;
    v[n-1]=(v[n-1]+k)%26;
    rep(i,n){
        cout<<char('a'+v[i]);
    }
    cout<<endl;
}


