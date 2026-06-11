#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    long long  w, h;
    long long eda = 0;
    cin >> w >> h;
    vector<ll> p;
    vector<ll> q;
    for(ll i = 0; i < w; i++){
        ll in;
        cin >> in;
        p.push_back(in);
    }
    for(ll i = 0; i < h; i++){
        ll in;
        cin >> in;
        q.push_back(in);
    }
    p.push_back(INF);
    q.push_back(INF);
    ll cost = 0;
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    ll need = (w + 1) * (h + 1) - 1;
    while(eda < need){
        if((p.back()) > (q.back())){
            eda += (w + 1);
            cost += (w + 1) * q.back();
            h--;
            //cout << q.back() << endl;
            q.pop_back();
        } else {
            eda += (h + 1);
            cost += (h + 1) * p.back();
            w--;
            //cout << p.back() << endl;
            p.pop_back();
        }
    }
    cout << cost << endl;
    return 0;
}