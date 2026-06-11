#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

struct res{
    ll w,l;
};

bool asc( const res& left, const res& right ) {
    return left.w == right.w ? left.l < right.l : left.w < right.w;
}

struct numdep{
    ll num;
    ll dep = 0;
};
static const ll MAX = 100001;
vector <numdep> children[MAX];
ll parent[MAX] = {};
ll dep[MAX] = {};

void calcD (ll s){
    vector <ll> v;
    for (ll i=0;i<children[s].size();i++){
        if(dep[children[s][i].num] == 0){
            calcD(children[s][i].num);
        }
        v.push_back(dep[children[s][i].num]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll ret = 0;
    for(ll i=0;i<v.size();i++){
        if(ret < v[i] + i + 1){
            ret = v[i] + i + 1;
        }
    }
//    cout << s << " " << ret << endl;
    dep[s] = ret;
}

int main(){
    

    ll n;
    cin >> n;
    vector <res> v;
    for (ll i=0;i<n-1;i++){
        res r;
        r.l = i+2;
        cin >> r.w;
        numdep p;
        p.num = r.l;
        children[r.w].push_back(p);
        parent[r.l] = r.w;
        v.push_back(r);
    }
//    for (ll i=1;i<=n;i++){
//        cout << i << " " << parent[i] << endl;
//    }
//    cout << endl;
//    for (ll i=1;i<=n;i++){
//        cout << i;
//        for (ll j=0;j<children[i].size();j++){
//            cout << " " << children[i][j].num;
//        }
//        cout << endl;
//    }
//    cout << endl;
    for (ll i=1;i<=n;i++){
        if(children[i].size() == 0){
            dep[i] = 1;
        }
    }
    calcD(1);
//    cout << endl;
//    for (ll i=1;i<=n;i++){
//        cout << i << " " << dep[i] << endl;
//    }
    cout << dep[1]-1 << endl;

}