#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<bool> b(n,true);
    int ans=0;
    for(int i = 0; i < n; i++) {
        if(a[a[i]]==i && b[i] && b[a[i]]){
            ans++;
            b[i]=false;
            b[a[i]]=false;
        }
    }

    cout << ans << endl;

    return 0;
}