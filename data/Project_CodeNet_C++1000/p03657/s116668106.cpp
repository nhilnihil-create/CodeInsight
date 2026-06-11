#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int a,b; cin >> a >> b;
    bool jud = false;

    if(a %3 == 0 || b %3 == 0 || (a+b) %3 == 0){
        jud = true;
    }

    if(jud) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}