#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPm(i,n) for(int i=(n)-1;i>=0;i--)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
typedef long long ll;
vector<int> ans;
void solve(int n){
    if(n == 0) return;
    int M = 0;
    while(n > M*(M+1)/2) M++;
    ans.push_back(M);
    solve(n-M);
}
int main(){
    int N;
    cin >> N;
    solve(N);
    REP(i,ans.size()) cout << ans[i] << endl;
    return 0;
}
