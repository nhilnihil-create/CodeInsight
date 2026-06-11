#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n;
    cin >> n;
    vi aux(n);
    for(int &i : aux)
        cin >> i;
    int one = 0;
    int even = 0;
    int four = 0;
    for(int i : aux){
        if(i % 4 == 0)
            four++;
        if(!(i & 1) && i % 4 != 0)
            even++;
        if(i & 1)
            one++;
    }
    if(even == 0)
        if(one <= four + 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    else{
        if(one <= four)
            cout << "Yes\n";
        else
            cout << "No\n";
    } 
    return 0;
}   