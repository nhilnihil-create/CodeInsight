#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

void solve()
{
    long long a,b,x;
    cin>>a>>b>>x;
    long long B=b/x+1;
    long long A=(a-1<0)?0:(a-1)/x+1;
    cout<<B-A<<endl;
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