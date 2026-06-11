#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
#define REP(i,n) for (int i = 0; i <(n); ++i)
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << 
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " ";} cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
    //input
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i,n) cin >> a[i];
    //sort
    sort(ALL(a));

    //sum
    int sum = 0;
    REP(i,n) sum += a[i];

    if(sum%10 != 0){
        cout << sum << endl;
        return 0;
    }
        //sum % 10 == 0
    //昇順にa[i] %10 != 0　を探す
    // ある場合は,それをひくない場合は0

    REP(i,n){
        if(a[i]%10 != 0){
            cout << sum - a[i] << endl;
            return 0;
        }
    }

  cout << 0 << endl;
  return 0;

}