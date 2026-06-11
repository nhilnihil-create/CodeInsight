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
int temp, ans;
bool sol;

int main(){
    ios::sync_with_stdio(0);
    cin >> s;
    s.pop_back();
    ans = 0;
    while(true){
        ans++;
        //cout << "NOW ON " << s << "\n";
        if(s.length()%2){
            s.pop_back();
            continue;
        }

        int temp = (int)s.length()/2;
        sol = true;
        forn(i,temp){
            if(s[i] != s[i+temp]){
                sol = false;
                break;
            }
        }

        if(sol){
            break;
        }else{
            s.pop_back();
        }
    }

    cout << s.length() << "\n";
    return 0;
}