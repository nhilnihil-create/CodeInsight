#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<int> f,b;
    rep(i,n){
        int a;cin>>a;
        if(i%2==0){
            b.push_back(a);
        }else{
            f.push_back(a);
        }
    }
    if(n%2==0){
        reverse(f.begin(),f.end());
        rep(i,f.size())cout<<f[i]<<" ";
        rep(i,b.size())cout<<b[i]<<" ";
        cout<<endl;
    }else{
        reverse(b.begin(),b.end());
        rep(i,b.size())cout<<b[i]<<" ";
        rep(i,f.size())cout<<f[i]<<" ";
        cout<<endl;
    }
    
}