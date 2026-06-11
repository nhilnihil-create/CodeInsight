#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
ll MOD = 1e9 + 7;
 
int main(){
    int n; string s,s2;
    cin >> n >> s >> s2;
    ll ans;
    vector<char> v;
    int i = 0;
    while(i < n) {
        if(s[i] == s[i + 1]) {
            v.pb('b');
            i += 2;
        }else{
            v.pb('a');
            i++;
        }
    }
    if(v[0] == 'a') ans = 3;
    else ans = 6;
    for(int j = 0;j < v.size() - 1;j++) {
        if(v[j] == 'a' && v[j+1] == 'a'){
            ans *= 2;
            ans %= MOD;
        }else if(v[j] == 'a' && v[j+1] == 'b'){
            ans *= 2;
            ans %= MOD;
        }else if(v[j] == 'b' && v[j+1] == 'b'){
            ans *= 3;
            ans %= MOD;
        }
    }
    cout << ans % MOD << endl;
}


