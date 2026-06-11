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

string a, b;

int main(){
    ios::sync_with_stdio(0);
    cin >> a >> b;

    if(b.size() > a.size()){
        cout << "LESS\n";
    }else if(a.size() > b.size()){
        cout << "GREATER\n";
    }else if(a == b){
        cout << "EQUAL\n";
    }else if(a > b){
        cout << "GREATER\n";
    }else{
        cout << "LESS\n";
    }

    return 0;
}