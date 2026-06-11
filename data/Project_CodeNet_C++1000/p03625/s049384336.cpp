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
    ll N;
    cin >> N;

    ll A;
    set<ll> singleEdge;
    map<ll, ll> pairEdge;

    rep(i, N){
        cin >> A;
        if(singleEdge.find(A) != singleEdge.end()){
            if(pairEdge.find(A) != pairEdge.end()){
                pairEdge[A]++;
            }else{
                pairEdge[A] = 2;
            }
        }else{
            singleEdge.insert(A);
        }
    }
    if(pairEdge.size() == 0 || (pairEdge.size() == 1 && pairEdge.rbegin()->second < 4)){
        cout << 0 << endl;
        return 0;
    }

    ll x, y;
    if(pairEdge.rbegin()->second >= 4){
        x = pairEdge.rbegin()->first;
        y = pairEdge.rbegin()->first;
    }else{
        x = pairEdge.rbegin()->first;
        pairEdge.erase(pairEdge.rbegin()->first);
        y = pairEdge.rbegin()->first;
    }

    cout << x * y << endl;

    return 0;
}