#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int n;
string s;
int cnt[4];

void solve(){
    cin >> s;
    n=s.length();
    rep(i,n){
        if(s[i]=='N') cnt[0]+=1;
        if(s[i]=='S') cnt[1]+=1;
        if(s[i]=='W') cnt[2]+=1;
        if(s[i]=='E') cnt[3]+=1;
    }
    if(cnt[0]>0 && cnt[1]==0){
        cout << "No" << endl;
        return;
    }
    if(cnt[1]>0 && cnt[0]==0){
        cout << "No" << endl;
        return;

    }
    if(cnt[2]>0 && cnt[3]==0){
        cout << "No" << endl;
        return;
    }
    if(cnt[3]>0 && cnt[2]==0){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}