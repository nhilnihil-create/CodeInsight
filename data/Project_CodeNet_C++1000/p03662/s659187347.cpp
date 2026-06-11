#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
int MOD = 1000000007;

using namespace std;

vector<int> r[100001];
int n;
int B[100001] = {0};
int W[100001] = {0};
int Bu[100001] = {0};
int Wu[100001] = {0};
int dfs_w(int x,int i){
    if(Wu[x] == 1 || x == 1)return 0;
    else{
        W[x] = i;
        Wu[x] = 1;
        for(auto y:r[x]) dfs_w(y,i+1);
    }
    return 0;
}

int dfs_b(int x,int i){
    if(Bu[x] == 1 || x == n)return 0;
    else{
        B[x] = i ;
        Bu[x] = 1 ;
        for(auto y:r[x]) dfs_b(y,i+1);
    }
    return 0;
}

signed main(){
       
    cin >>  n;
    
    REP(i,n-1){
        int a,b;
        cin >> a >> b;
        r[a].pb(b);
        r[b].pb(a); 
    }
    dfs_b(1,1);
    dfs_w(n,1);

    // int x1 = x2 = x3 = x4 = -1;
    // REP(i,n){
    //     if(abs(B[i+1]-W[i+1]) == 0 && W[i+1] != 0 && B[i+1] != 0) x1 = i+1;
    //     if(B[i+1]-W[i+1] == 2 && W[i+1] != 0 && B[i+1] != 0) x2 = i+1;
    //     if(B[i+1] - W[i+1] == 1 && W[i+1] != 0 && B[i+1] != 0) x3 = i+1;
    //     if(B[i+1] - W[i+1] == -1 && W[i+1] != 0 && B[i+1] != 0) x4 = i+1;
    // }
    int cntBW = 0;
    int cntB = 0;
    int cntW = 0;
    REP(i,n){
        if(B[i+1] != 0 && W[i+1] != 0 && B[i+1] <= W[i+1])cntB++;
        else if(B[i+1] != 0 && W[i+1] != 0 && B[i+1] > W[i+1])cntW++;
        else if(B[i+1] == 0 && W[i+1] != 0) cntW++;
        else if(B[i+1] != 0 && W[i+1] == 0) cntB++;
  
    }
    if(cntW >= cntB)cout << "Snuke" << endl;
    else cout << "Fennec" << endl;
    // REP(i,n){
    //     cerr << " " << cntBW/2 + cntW << " "<< (cntBW - cntBW/2) + cntB << endl;;
    // }


    

    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 