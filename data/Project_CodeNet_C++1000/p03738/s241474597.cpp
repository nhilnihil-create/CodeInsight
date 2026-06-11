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
    string A,B;
    cin >> A >> B;
    if(A.size() > B.size()){
        cout << "GREATER" << "\n";
    }else if(A.size() < B.size()){
        cout << "LESS" << "\n";
    }else if(A == B){
        cout << "EQUAL" << "\n";
    }else{
        REP(i,A.size()){
            if(A[i] == B[i])continue;
            if(A[i] > B[i]){
                cout << "GREATER" << "\n";
                break;
            }else{
                cout << "LESS" << "\n";
                break;
            }
        }
    }
}