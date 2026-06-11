#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>
#include <utility>
#include <stack>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;

ll p[101000], q[101000];
int main(){
    ll W, H;
    priority_queue<T, vector<T>, greater<T> > que;
    cin >> W >> H;
    for(int i = 0; i < W; i++){
        cin >> p[i];
        que.push(T(p[i], P(i, 0)));
    }
    for(int i = 0; i < H; i++){
        cin >> q[i];
        que.push(T(q[i], P(i, 1)));
    }

    W++; H++;
    ll res = 0;
    ll w = W, h = H;
    ll edgeNum = 0;
    while(!que.empty()){
        T nex = que.top(); que.pop();
        if(nex.sc.sc == 0){
            res += h * nex.fs;
            w--;
            edgeNum += w;
//            cout << "w: " << w << endl;
        }
        else{
            res += w * nex.fs;
            h--;
            edgeNum += w;
//            cout << "h: " << h << endl;
        }
//        cout << nex.fs << " " << res << " " << edgeNum << endl;
    }
//    cout << edgeNum << endl;

    cout << res << endl;




    return 0;
}