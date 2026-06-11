#include <bits/stdc++.h>
using namespace std;

#define sfi(x) scanf("%d", &x)
#define pii pair<int, int>

int main(){
    int n, t;
    cin >> n >> t;
    int a[n+5];
    for(int i=0; i<n; i++)
        cin >> a[i];

    int m[n+5] = {0};
    for(int i=n-1; i>=0; i--)
        m[i] = max(a[i], m[i+1]);

//    for(int i=0; i<n; i++)
//        cout << m[i] << " ";
//        cout << endl;

    int best = 0;
    for(int i=0; i<n-1; i++)
        if(a[i] < m[i+1])
            best = max(best, m[i+1] - a[i]);

//    cout << best << endl;
    int ans = 0;
    for(int i=0; i<n-1; i++)
        if(a[i]<m[i+1] && m[i+1]-a[i]==best)
            ans++;
    cout << ans << "\n";
    return 0;
}
