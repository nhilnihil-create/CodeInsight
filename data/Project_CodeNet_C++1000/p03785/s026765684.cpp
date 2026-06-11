#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N;
    LL C, K;
    cin >> N >> C >> K;
    vector<LL> T(N);
    REP(i,N)cin>>T[i];

    sort(T.begin(), T.end());
    int count = 0;
    LL time = T[0];
    LL man = 0;
    REP(i,N){
        man++;

        if(man>C || T[i]>time+K){
            count++;
            time = T[i];
            man = 1;
        }        
        
    }

    if(man!=0){count++;}

    cout << count << endl;
    return 0;

}