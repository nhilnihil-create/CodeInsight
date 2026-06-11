#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int d=0;
    int q=0;
    int o=0;
    for(int i = 0; i < n; i++) {
        if(a[i]%4==0)      q++;
        else if(a[i]%2==0) d++;
        else               o++;
    }

    if((d==0 && q>=o-1) || (d==n) || (q>=o)) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}