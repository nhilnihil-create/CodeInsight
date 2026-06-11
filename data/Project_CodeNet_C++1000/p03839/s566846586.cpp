#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // cumulative sum
    vector<long long int> sa_all(n+1), sa_positive(n+1);
    for(int i=0; i<n; i++){
        sa_all[i+1] = sa_all[i] + a[i];
        sa_positive[i+1] = sa_positive[i] + max(0LL, a[i]);
    }

    long long int ans = 0;
    for(int i=0; i+k<=n; i++){
        long long int test = sa_positive[i] 
                           + max(0LL, sa_all[i+k] - sa_all[i]) 
                           + (sa_positive[n] - sa_positive[i+k]);
        ans = max(ans, test);
    }
    cout << ans << endl;
    return 0;
}