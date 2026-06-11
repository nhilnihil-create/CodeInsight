#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector <ll> g[10];
ll visited[10];
int main(){
    ll x;
    cin >> x;
    ll ans=0;
    ans+=(x-1)/11*2;
    if((x-1)%11>=6)ans+=2;else ans++;
    cout << ans;
    return 0;
}
