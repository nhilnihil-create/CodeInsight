#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define push push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<long long> V;
typedef vector<V> VV;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<62;
const int INF = 1<<30;
int main(){
    int k,t;
    int ans=0;
    cin >>k>>t;
    vector<int>a(t,0);
    rep(i,t){
        cin>>a[i];
    }
    sort(all(a),greater<int>());

    cout<<max(a[0]-(k-a[0])-1,0)<<endl;
}