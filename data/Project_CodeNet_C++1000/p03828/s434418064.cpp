#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;

void solve()
{
    int N; cin>>N;
    const int MOD=1000000007;
    map<int,int> M;
    for (int i = 2; i <= N; ++i) {
        int tmp=i;  
        for (int j = 2; j <= tmp ; ++j){
            while(tmp%j==0){
                M[j]++; tmp/=j;
            }
        }
    }
    long long ans=1;
    for(auto m:M){
        ans=(ans*(m.second+1))%MOD;
    }
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    // input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}