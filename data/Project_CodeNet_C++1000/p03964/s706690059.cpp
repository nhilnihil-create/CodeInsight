//#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}//GCD

ll lcm(ll a,ll b){
    if(a==0||b==0){
        return 0;
    }
    return a*b/gcd(a,b);
}

int main(){
    ll n;
    cin >> n;
    ll p=1,q=1;
    //cerr<<endl;
    //cerr<<endl;
    rep(i,n){
        ll t, a;
        cin >> t>>a;
        
        ll m=max((p-1)/t+1,(q-1)/a+1);
        p=t*m;q=a*m;
        
        //cerr<<p<<' '<<q<<endl;
    }
    cout<<p+q<<endl;
    return 0;
}