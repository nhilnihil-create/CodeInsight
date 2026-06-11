#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve()
{
    int N; cin >> N;
    map<int,int> M;
    for (int i = 0; i < N; ++i){
        int a; cin >> a;
        M[a]++;
    }

    int ans = 0;
    vector<int> a,b;
    for(auto m:M) a.emplace_back(m.first),b.emplace_back(m.second);
    for (int i = 0; i < a.size(); ++i) {
        int sum = b[i];
        if(i>0 && a[i]-a[i-1]==1) sum += b[i-1];
        if(i+1<a.size() && a[i+1]-a[i]==1) sum += b[i+1];
        ans = max(ans,sum);
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