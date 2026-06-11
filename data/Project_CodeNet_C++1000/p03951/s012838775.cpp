#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    string s,t;
    cin >> n >> s >> t;
    int id = 0;
    while(id < n){
        if(s.substr(id,n - id) == t.substr(0, n - id)){
            break;
        }else id++;
    }
    int ans =  n*2 - s.substr(id,n - id).size();
    cout << ans << endl;
    return 0;
}