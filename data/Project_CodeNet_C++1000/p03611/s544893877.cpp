#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int>cnt(1e6,0);
    for(int x:a){
        if(x-1>=0) cnt[x-1]++;
        cnt[x]++;
        cnt[x+1]++;
    }
    sort(cnt.begin(),cnt.end());
    reverse(cnt.begin(),cnt.end());
    cout << cnt[0] << endl;
}