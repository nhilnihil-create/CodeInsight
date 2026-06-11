#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    vector<ll> A(3);
    REP(i,3)cin >> A[i];
    sort(ALL(A));
    int sum = A[0]+A[1]+A[2];
    if(A[0] == A[1] && A[1] == A[2]){
        cout << (A[0]%2?0:-1) << "\n";
    }else{
        for(int i = 0;;i++){
            if(A[0]%2 == 0&&A[1]%2 == 0&&A[2]%2 == 0){
                REP(l,3)A[l] = (sum - A[l])/2;
            }else{
                cout << i << "\n";
                break;
            }
        }
    }
}