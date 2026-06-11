#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
typedef tuple<ll, ll, ll> T;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> v(3*n);
    REP(i,3*n) cin>>v[i];
    priority_queue<ll, vector<ll>,greater<ll>> lque;
    priority_queue<ll, vector<ll>> sque;
    ll ls=0,ss=0;
    vector<ll> lv;
    vector<ll> sv;
    REP(i,n){
        lque.push(v[i]);
        sque.push(v[2*n+i]);
        ls+=v[i];
        ss+=v[2*n+i];
    }
    lv.push_back(ls);
    sv.push_back(ss);
    ll ans = -1e18;
    ans = max(ans,ls-ss);
    REP(i,n){
        lque.push(v[n+i]);
        sque.push(v[2*n-i-1]);
        ls += v[n+i] - lque.top();
        ss += v[2*n - i - 1] - sque.top();
        lv.push_back(ls);
        sv.push_back(ss);
        sque.pop();
        lque.pop();
    }
    REP(i,lv.size()) ans=max(ans,lv[i]-sv[n-i]);
    cout<<ans<<endl;

}