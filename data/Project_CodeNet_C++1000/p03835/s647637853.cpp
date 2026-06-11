#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    ll k,s,ans=0;
    cin >> k >> s;
    for(int x=0;x<=k;x++){
        for(int y=0;y<=k;y++){
            int z = s - x - y;
            if(z < 0 || z > k)continue;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}