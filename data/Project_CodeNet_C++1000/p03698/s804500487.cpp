//
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MOD 1000000007
#define PI 3.14159265
#define EPS 1e-9
#define Pi acos(-1.0)
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define clean(arr,val) memset(arr,val,sizeof(arr))
#define forn(i,n) forr(i,0,n)
#define PB push_back
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pll> vpll;

/*CODE START HERE*/

string s;
int appear[30];
bool sol;

int main(){
    ios::sync_with_stdio(0);
    cin >> s;
    clean(appear,0);
    sol = true;
    forn(i,(int)s.size()){
        if(appear[s[i]-'a'] != 0){
            sol = false;
            break;
        }
        appear[s[i]-'a']++;
    }

    if(sol){
        cout << "yes\n";
    }else{
        cout << "no\n";
    }
    return 0;
}