#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<double, double> Pdd;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;

const ll mod = 1e9+7;
const int INF = 2e9;
const double epsilon = 1e-7;
const double PI = 3.1415926535;

ll mi(ll x, ll y){
    if(x<y)return x;
    return y;
}

vector <int> v[100000];
priority_queue <int, vector<int>, greater<int>> p[100000];

int depth(int k){
    if(v[k].size() == 0)return 0;
    for(int i = 0;i < v[k].size();i++){
        p[k].push(depth(v[k][i]));
    }
    int maa = 0;
    for(int i = 0;i < v[k].size();i++){
        int pi = p[k].top(); p[k].pop();
        if(pi + v[k].size() - i > maa)maa = pi + v[k].size() - i;
    }
    //cout << k << " " << maa << endl;
    return maa;
}
int main(void){
    int n; cin >> n;
    for(int i = 0;i < n - 1;i++){
        int a; cin >> a; a--; v[a].push_back(i+1);
    }
    cout << depth(0) << endl;
 	return 0;
}
