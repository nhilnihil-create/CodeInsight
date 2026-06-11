#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main(){
    ll n;
    cin >> n;
    n++;
    VI a;
    while (n){
        a.push_back(n%2);
        n /= 2;
    }
    reverse(ALL(a));
    int m = a.size();
    // REP(i,m) cout << a[i];
    // cout << endl;
    deque<int> ans;
    int x = 1;
    FOR(i,1,m-1){
        ans.push_back(x++);
        if (a[i]) ans.push_front(x++);
    }

    cout << ans.size() * 2 << endl;
    FOR(i,1,ans.size()) cout << i << " ";
    while (!ans.empty()){
        cout << ans.front() << " ";
        ans.pop_front();
    }
    cout << endl;

    return 0;
}