#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int,int> m;
    rep(i,0,N) {
        int x;
        cin >> x;
        m[x]++;
    }
    ll ans=0LL;
    vector<int> a;
    for (auto p : m) {
        if (p.second>=4) ans=1LL*p.first*p.first;
        if (p.second>=2) a.push_back(p.first);
    }
    if (a.size()>=2) ans=max(ans,1LL*a[a.size()-1]*a[a.size()-2]);
    cout << ans << endl;
}
