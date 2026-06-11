#include <bits/stdc++.h>
#define ll long long
#define REV(v) reverse(v.begin(), v.end());
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, start, stop) for (int i = start; i < stop; i++)
#define FORR(i, start, stop) for (int i = start; i > stop; i--)
#define SORT(v, n) sort(v, v + n);
#define SORTR(v, n) sort(v, v + n,greater<int>());
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.begin(), v.end(),greater<ll>());
#define REMOVE(v,n) remove(vector<ll> v,v+v.size(),ll n)
#define ERASE(v,n) v.erase(v.begin()+n);
#define ull unsigned long long
#define pb(a) push_back(a)
#define INF 999999999
#define V(v,i,j) vector(v.begin() + i, v.begin() + j)
#define INSERT(va,vb) va.insert(va.end(), vb.begin(), vb.end())
using namespace std;
typedef vector<int> vint;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
const int MOD = 1000000007;
void chmin(int &a, int b) { if (a > b) a = b; }

//vector< vector<int> > v (size1, vector<int>(size2) );

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin>>N;
    vector<ll> p(N);
    FOR(i,0,N) cin>>p[i];

    ll ans=0;

    FOR(i,0,N-1){
        if(i+1==p[i]){
            swap(p[i],p[i+1]);
            ans++;
        }
    }
    if(p[N-1]==N){
        swap(p[N-1],p[N-2]);
        ans++;
    }
    
    cout<<ans<<endl;
}