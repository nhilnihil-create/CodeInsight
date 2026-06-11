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
    cin >> N;
    vector<LL> A(N);
    vector<LL> B(N);   
    REP(i,N)cin>>A[i]>>B[i];

    LL ans = 0;
    for(int i=N-1; i>=0; i--){
        LL r = (A[i]+ans) % B[i];
        if(r==0){continue;}

        ans += B[i] - r;
    }

    cout << ans << endl;
    return 0;
}