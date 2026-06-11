#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N, M;
    cin >> N >> M;

    int a, b;
    vector<bool> IsBFrom0(N,false);
    vector<bool> IsAToN(N,false);
    
    REP(i,M){
        cin >> a >> b;
        if(a==1){
            IsBFrom0[b-1]=true;
        }
        if(b==N){
            IsAToN[a-1]=true;
        }
    }

    REP(i,N){
        if(IsAToN[i]==true && IsBFrom0[i]==true){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}