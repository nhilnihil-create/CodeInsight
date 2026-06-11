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
    map<int, int>mp;
    rep(i,0,n){
        int tmp;
        cin >> tmp;
        mp[tmp]++;
        mp[tmp-1]++;
        mp[tmp+1]++;
    }
    int ans = 0;
    for(auto a: mp){
        if(ans < a.second){
            ans = a.second;
        }
    }
    cout << ans << endl;
    return 0;
}
