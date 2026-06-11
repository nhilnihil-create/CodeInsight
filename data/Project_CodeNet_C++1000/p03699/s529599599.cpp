#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
typedef long long ll;

vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];
int main() {
    
    int n;
    cin >> n;
    int sum = 0;
    vector<int> s(n);
    vector<int> t(n+1);
    rep(i,0,n){
        cin >> s[i];
        sum+=s[i];
        t[i+1] = t[i]+s[i];
    }
    
    int ans = 0;
    rep(i,0,n){
        if((sum-s[i])%10)ans = max(sum-s[i], ans);
    }
    rep(i,0,n){
        if(sum%10)ans = max(sum, ans);
        sum-=s[i];
    }
    cout << ans << endl;
    return 0;
}
