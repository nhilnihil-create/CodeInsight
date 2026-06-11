#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i=0; i<n; i++)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define reprs(i, s, e) for(int i=e-1; i>=s; i--)

const int MOD = 1e9 + 7;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    vector<bool> isVert;
    rep(i, n){
        if(s1[i] == s1[i+1]){
            isVert.push_back(false);
            i++;
        }
        else{
            isVert.push_back(true);
        }
    }

    ll cnt = 0;
    if(isVert[0] == true){
        cnt = 3;
    }
    else{
        cnt = 6;
    }

    reps(i, 1, isVert.size()){
        if(isVert[i-1] == true){
            cnt = (cnt * 2) % MOD;
        }
        else{
            if(isVert[i] == false){
                cnt = (cnt * 3) % MOD;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}