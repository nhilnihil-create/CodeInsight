#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    string S;
    cin >> S;

    ll hash[S.size() + 1];
    hash[0] = 0;
    REP(i, S.size()){
        hash[i] = hash[i - 1] + S[i - 1] * S[i - 1];
    }

    ll ans = (S.size() - 1) / 2;
    bool searching = true;
    while(searching && ans > 0){
        if(hash[ans] - hash[0] == hash[2 * ans] - hash[ans]){
            REP(i, ans){
                if(S[ans - i] != S[2 * ans - i]){
                    break;
                }
                if(i == ans){
                    searching = false;
                }
            }
        }
        if(searching){
            ans--;
        }
    }

    cout << ans * 2 << endl;

    return 0;
}