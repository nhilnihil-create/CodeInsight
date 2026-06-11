#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define P pair<int, int>
#define Pl pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;


int main()
{
  string S; cin >> S;
  reverse(S.begin(), S.end());
  int sz = S.size(); --sz;
  int index = 0;

  while(index < sz){
    if(S.substr(index, 5) == "maerd") index += 5;
    else if(S.substr(index, 7) == "remaerd") index += 7;
    else if(S.substr(index, 6) == "resare") index += 6;
    else if(S.substr(index, 5) == "esare") index += 5;
    else { cout << "NO" << endl;return 0;}
  }

  cout << "YES" << endl;
}