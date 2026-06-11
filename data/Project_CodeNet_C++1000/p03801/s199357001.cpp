#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int N;
ll A[100009], ret[100009];
vector<int> V;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    map<ll,ll> M;
    rep(i,N) cin>>A[i], M[A[i]]++;
    V.push_back(0);
    rep1(i,N-1) if(A[V.back()]<A[i]) V.push_back(i);
    rrep(i,V.size()-2){
        while(M.rbegin()->first>A[V[i]]){
            auto r=*M.rbegin();
            M.erase(r.first);
            ret[V[i+1]]+=(r.first-A[V[i]])*1LL*r.second;
            M[A[V[i]]]+=r.second;
        }
    }
    for(auto& r:M) ret[0]+=r.first*r.second;
    rep(i,N) cout1(ret[i]);
}