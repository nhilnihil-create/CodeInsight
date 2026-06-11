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
#include <random>
#include <cassert>
#include <numeric>
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

ll y[10000005];

int main() {
    int x, y,ans;
    cin >> x >> y;

    if(x < y){
        if(x>=0&&y>0) ans = y - x;
        else if(x<0&&y>0){
            if(abs(x) <= abs(y)) ans = 1 + y + x;
            else ans = -1 * y - x + 1;
        }else {
            ans = y - x;
        }
    }else{
        if(x>0&&y>0) ans = 2 + -1*y + x;
        else if(x==0){
            ans = 1 + -1 * y;
        }else if(y==0) {
            ans = 1 + x;
        }else if(x>0&&y<0){
                if(abs(x) >= abs(y)) ans = 1 + y + x;
                else ans = -1 * y - x + 1;
        }else {
            ans = -1 * y + x + 2;
        }
    }
    cout << ans << endl;
}
