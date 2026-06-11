#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    LL N, A, B;
    cin >> N >> A >> B;
    LL min_sum = (N-2)*A;
    LL max_sum = (N-2)*B;

    if(min_sum > max_sum){
        cout << 0 << endl;
    }else{
        cout << max_sum - min_sum + 1 << endl;
    }
    return 0;

}