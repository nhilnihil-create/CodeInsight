#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 998244353
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 5000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(){
    string s; cin>>s;
    if(s.front()==s.back()){
        if(s.size()%2==1)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }else{
        if(s.size()%2==0)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}