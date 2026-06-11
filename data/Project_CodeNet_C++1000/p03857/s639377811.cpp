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
int par[200050];
int rank1[200050];

void init(int n)
{
    for(int i = 0; i < n; i++){
        par[i] = i;
        rank1[i] = 0;
    }
}

int find(int x)
{
    if(par[x] == x){
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y){
        return ;
    }
    if(rank1[x] , rank1[y]){
        par[x] = y;
    } else {
        par[y] = x;
        if(rank1[x] == rank1[y]){
            rank1[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}
int par2[200050];
int rank2[200050];

void init2(int n)
{
    for(int i = 0; i < n; i++){
        par2[i] = i;
        rank2[i] = 0;
    }
}

int find2(int x)
{
    if(par2[x] == x){
        return x;
    } else {
        return par2[x] = find2(par2[x]);
    }
}

void unite2(int x, int y)
{
    x = find2(x);
    y = find2(y);
    if(x == y){
        return ;
    }
    if(rank2[x] , rank2[y]){
        par2[x] = y;
    } else {
        par2[y] = x;
        if(rank2[x] == rank2[y]){
            rank2[x]++;
        }
    }
}

bool same2(int x, int y)
{
    return find2(x) == find2(y);
}

int main() {
    //cout.precision(10);
    int n, k, l;
    cin >> n >> k >> l;
    init(n + 2);
    init2(n + 2);
    vector<int> road[n + 1];
    vector<int> train[n + 1];
    for(int i = 1; i <= k; i++){
        int in1, in2;
        cin >> in1 >> in2;
        unite(in1, in2);
    }
    for(int i = 1; i <= l; i++){
        int in1, in2;
        cin >> in1 >> in2;
        unite2(in1, in2);
    }
    for(int i = 1; i <= n; i++){
        find(i);
        road[par[i]].push_back(i);
        find2(i);
        train[par2[i]].push_back(i);
    }
    vector<pair<int, int> > parent;
    for(int i = 1; i <= n; i++){
        pair<int, int> in;
        in.first = par[i];
        in.second = par2[i];
        parent.push_back(in);
    }
    sort(parent.begin(), parent.end());
    for(int i = 1; i <= n; i++){
        pair<int, int> checker;
        checker.first = par[i];
        checker.second = par2[i];
        cout << distance(lower_bound(parent.begin(), parent.end(), checker), upper_bound(parent.begin(), parent.end(), checker));
        if(i < n){
            cout << " ";
        }
    }
    cout << endl;
    /*}
    for(int i = 1; i <= n; i++){
        sort(train[i].begin(), train[i].end());
    }
    for(int i = 1; i <= n; i++){
        int ans = 0;
        for(int j = 0; j < road[par[i]].size(); j++){
            ans += distance(lower_bound(train[par2[i]].begin(), train[par2[i]].end(), road[par[i]][j]), upper_bound(train[par2[i]].begin(), train[par2[i]].end(), road[par[i]][j]));
        }
        cout << ans;
        if(i < n){
            cout << " ";
        }
    }
    cout << endl;*/
    return 0;
}
