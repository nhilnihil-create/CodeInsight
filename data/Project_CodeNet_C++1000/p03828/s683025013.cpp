#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x, ans=1;
    cin >> n;
    map<int, int> cnt;
    for(int i=2; i<=n; i++) {
        x=i;
        for(int j=2; j<=i*i; j++) {
            while(x%j==0) {
                if(cnt.count(j)) cnt[j]++;
                else cnt[j]=1;
                x /=j;
            }
            if(x==1) break;
        }
        if(x!=1) cnt[x]=1;
    }
    for(int i=2; i<=n; i++) {
        if(cnt.count(i)) {
            ans*=(cnt[i]+1);
        }
        ans%=1000000007;
    }
    cout << ans;
}