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

LL comb(LL value, LL cnt);

int main(){
    int N, P;
    cin >> N >> P;
    vector<int> A(N);
    REP(i,N)cin>>A[i];

    int count_even = 0;
    int count_odd = 0;
    REP(i,N){
        if(A[i]%2==0){
            count_even++;
        }else{
            count_odd++;
        }
    }

    LL comb_even = 0;
    LL comb_odd = 0;

    for(int i=0; i<=count_even; i++){
        comb_even += comb(count_even, i);
    }

    for(int j=P; j<=count_odd; j+=2){
        comb_odd += comb(count_odd, j);
    }

    cout << comb_even*comb_odd << endl;
    return 0;
}

LL comb(LL value, LL cnt){
    if(cnt==0){return 1;}
    LL ans = 1;
    for(LL i=0; i<cnt; i++){
        ans *= (value-i);
        ans /= (i+1);
    }
    return ans;
}
