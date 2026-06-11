#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
ll INF = 214748364700000000;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

bool F(string S){
    rep(i,26){
        if(count(ALL(S),'a'+i) >= 2) return true;
    }
    return false;
}

int main(){
   string S;
   cin >> S;
   rep(i,S.size()-1){
       if(S[i] == S[i+1]){
           cout << i+1 << ' ' << i+2 << endl;
           return 0;
       }
   }
   rep(i,S.size()-2){
       if(F(S.substr(i,3))){
           cout << i+1 << ' ' << i+3 << endl;
           return 0;
       }
   }
   cout << "-1 -1" << endl;
}
