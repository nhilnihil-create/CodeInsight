#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    bool flag = true;
    FOR(i,1,n-1){
      if(s[i-1] == s[i+1])continue;
      else flag = false;
    }

    if(flag == true ){
      cout << "Second" << endl;
      return 0;
    }
    //cout << "hi" << "\n";
    if(((n-2) % 2 == 0) ^ (s[0] == s.back() ) ){
      cout << "Second" << "\n";
    }else{
      cout << "First" << "\n";
    }
    return 0;
}
