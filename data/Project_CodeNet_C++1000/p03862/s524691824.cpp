#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

void solve()
{
    int N,x; cin>>N>>x;
    vector<int> a(N+1),s(N+1,0);
    for (int i = 0; i < N; ++i) cin>>a[i];
    long long ans = 0;
    for (int i = 0; i < N-1; ++i){
        if(a[i]+a[i+1]>x){
            ans+=a[i]+a[i+1]-x;
            a[i+1]=max(0,x-a[i]);
        }
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