#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    vector<long long> ans(n, 0);

    for(long long i = 0; i < m; i++){
        long long a, b;
        cin >> a >> b;
        ans[a-1]++;
        ans[b-1]++;
    }

    for(long long i = 0; i < n; i++){
        printf("%lld\n", ans[i]);
    }
    return 0;
}