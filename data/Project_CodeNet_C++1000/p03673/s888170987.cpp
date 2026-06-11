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
    ll n;
    cin >> n;

    deque<ll> q;
    ll a;
    rep(i, n){
        cin >> a;
        if(i % 2 == 0){
            q.push_back(a);
        }else{
            q.push_front(a);
        }
    }

    if(n % 2 == 0){
        rep(i, n){
            if(i != 0){
                cout << " ";
            }
            cout << q.front();
            q.pop_front();
        }
    }else{
        rep(i, n){
            if(i != 0){
                cout << " ";
            }
            cout << q.back();
            q.pop_back();
        }
    }
    cout << endl;

    return 0;
}