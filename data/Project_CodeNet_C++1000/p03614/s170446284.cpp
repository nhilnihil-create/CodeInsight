#include "bits/stdc++.h"
using namespace std;

#define Rep(i,n) for(int i=0;i<n;i++)
#define For(i,n1,n2) for(int i=n1;i<n2;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define RREP(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define put(a) cout<<a<<"\n";
#define all(a)  (a).begin(),(a).end();
#define SORT(a) sort((a).begin(),(a).end())
#define TDARRAY(int,a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()

typedef long long ll;
typedef pair<int, int> P;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b){a=b;return 1;}return 0;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b){a=b;return 1;}return 0;}

int n;

int main(){
    cin >> n;
    vector<int> p(n);
    REP(i,n){
        cin >> p[i];
    }
    p.push_back(1e6);
    int con = 0;
    int res = 0;
    REP(i,n+1){
        if(i+1==p[i]){
            con++;
        }else{
            res+=(con+1)/2;
            con = 0;
        }
    }
    put(res);
    return 0;
}
