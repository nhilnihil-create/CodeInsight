#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
const int max_n= 10000;
int n,W,L,kk,m,V,e,r,ML, MD, E, v, H;
const int INF = 1e9+1;
const int mod = 1e9 + 7;
bool used[max_n][max_n];
string s1,s2;
int x[max_n],y[max_n],table[max_n][max_n],d[max_n][max_n],ppar[max_n],rrank[max_n],spf[max_n],a[max_n],b[max_n],c[max_n];
typedef pair<long , long> pii;
vector<long long> G[max_n];
vector<int> ls;
vector<pair<int, int> > edgee[max_n];
struct edge{
    int from,to,cost;
};
bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;   
}
edge es[max_n];
typedef pair<int, int> P;
struct Cmp{
    bool operator()(const pii &a,const pii &b){
        return a.second > b.second;
    }
};
void warshall_floyd(){
    for(int k=0 ; k<n ; k++){
         for(int i=0 ; i<n ; i++){
              for(int j=0 ; j<n ; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
void solve(){
    warshall_floyd();
    long long count = 0;
    for(int i=0 ; i<m ; i++){
        if(c[i] > d[a[i]][b[i]])    count++;
    }
    cout << count << endl;
}
int main(){
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            d[i][j] = INF;
            if(i == j)  d[i][j] = 0;       
        }
    }
    for(int i=0 ; i<m ; i++){
           cin >> a[i] >> b[i] >> c[i];
            --a[i]; --b[i];
            d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
        
    }
    solve();
    return 0;
}