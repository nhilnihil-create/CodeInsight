#include <iostream>
#include <map>
using namespace std;


void solve()
{
    int N; cin >> N;
    map<long long,int> M;
    for (int i = 0; i < N; ++i) {
        long long a; cin >> a;
        M[a]++;
    }
    int ans = 0;
    for(auto m: M){
        if(m.second % 2 == 1) ++ans;
    }
    cout << ans << endl;
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