#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.sise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int l[200005];
int main(){
    int n,x;
    cin >> n>> x;
    set<int> s;
    if(x==1||x==2*n-1){
        cout<<"No"<<endl;
    }else{
        rep(i,2*n-1){
            s.insert(i+1);
        }
        l[n]=x;
        l[n-1]=x-1;
        l[n+1]=x+1;
        s.erase(x);
        s.erase(x-1);
        s.erase(x+1);
        rep2(i,2*n-1){
            if(i!=n-1&&i!=n&&i!=n+1){
                l[i]=*s.begin();
                s.erase(l[i]);
            }
        }
        cout<<"Yes"<<endl;
        rep2(i,2*n-1){
            cout<<l[i]<<endl;
        }
    }
    return 0;
}