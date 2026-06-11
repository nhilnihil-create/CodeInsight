#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    string s; cin >> s;
    if(s[0] == s[s.size()-1]){
        if(s.size() % 2 == 0){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }else{
        if(s.size() % 2 == 0){
            cout << "Second" << endl;
        }else{
            cout << "First" << endl;
        }
    }
}