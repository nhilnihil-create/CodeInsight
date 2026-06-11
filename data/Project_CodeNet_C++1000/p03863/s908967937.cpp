#include <bits/stdc++.h>
#define ll long long
#define REV(v) reverse(v.begin(), v.end());
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, start, stop) for (ll i = start; i < stop; i++)
#define FORR(i, start, stop) for (ll i = start; i > stop; i--)
#define SORT(v, n) sort(v, v + n);
#define SORTR(v, n) sort(v, v + n,greater<ll>());
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
typedef vector<ll> vll;
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
    string s;
    cin>>s;
    ll n;
    n=s.size();

    char ri_s,le_s;
    le_s=s[0];
    ri_s=s[n-1];
    if(s[0]!=s[n-1]){
        ll ri=0;
        ll le=0; 
        FOR(i,0,n){
            if(s[i]==ri_s)ri++;
            if(s[i]==le_s)le++;
        }
        if((n-2*min(ri,le))%2==0)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }else{
        if(n%2==1)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    
    return 0;
}