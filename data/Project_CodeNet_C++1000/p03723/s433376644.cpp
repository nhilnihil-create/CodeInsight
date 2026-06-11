#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

int main() {
    ll a,b,c,ans=0; cin >> a >> b >> c;
    ll A = a, B = b, C = c;
    while(a%2==0 && b%2==0 && c%2==0){
        int x = b/2 + c/2;
        int y = a/2 + c/2;
        int z = a/2 + b/2;
        a = b = c = 0;
        a += x;
        b += y;
        c += z;
        if(a == A && b == B && c == C){cout << -1 << endl; return 0;}
        ans++;
    }
    cout << ans << endl;
}



