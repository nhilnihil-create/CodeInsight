#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    vector<int> a(n);for(int i=0;i<n;i++) cin >> a[i];  
    int p=0,now=0;
    for(int i = 0; i < n; i++) {
        p++;
        now=a[now]-1;
        if(now==1){
            cout << p << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}