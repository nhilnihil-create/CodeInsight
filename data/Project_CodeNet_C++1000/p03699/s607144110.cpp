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
    rep(i,0,n){
        cin >> s[i];
        sum+=s[i];
    }
    sort(s.begin(), s.end());
    rep(i, 0, n){
        if(sum%10){
           cout << sum << endl;
           return 0;
        }
        if(s[i]%10){
            sum-=s[i];
        }
    }
    cout << sum%10 << endl;
    return 0;
}
