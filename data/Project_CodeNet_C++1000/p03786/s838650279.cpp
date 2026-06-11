#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // cumulative sum
    vector<long long int> sa(n+1);
    for(int i=0; i<n; i++){
        sa[i+1] = sa[i] + a[i];
    }

    int ans = 1;
    for(int i=n-1; i>=0; i--){
        if(a[i] <= 2 * sa[i]) ans += 1;
        else break;
    }
    cout << ans << endl;
    return 0;
}