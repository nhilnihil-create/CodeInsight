#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

void solve()
{
    long long N; cin>>N;
    int n = sqrt(N);
    long long A,B;
    for (int i = 1; i <= n; ++i){
        if(N%i==0) A=i,B=N/i;
    }
    int a=0,b=0;
    while(A!=0) A/=10,++a;
    while(B!=0) B/=10,++b;
    cout << max(a,b) << endl;
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