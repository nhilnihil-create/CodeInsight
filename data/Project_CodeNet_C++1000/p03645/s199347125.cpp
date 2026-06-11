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
    ll N, M;
    cin >> N >> M;

    ll from1[N + 1];
    ll toN[N + 1];
    REP(i, N){
        from1[i] = 0;
        toN[i] = 0;
    }

    ll a, b;
    rep(i, M){
        cin >> a >> b;
        if(a == 1){
            from1[b] = 1;
        }else if(b == 1){
            from1[a] = 1;
        }else if(a == N){
            toN[b] = 1;
        }else if(b == N){
            toN[a] = 1;
        }
    }

    bool possible = false;
    REP(i, N){
        if(from1[i] == 1 && toN[i] == 1){
            possible = true;
            break;
        }
    }

    if(possible){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}