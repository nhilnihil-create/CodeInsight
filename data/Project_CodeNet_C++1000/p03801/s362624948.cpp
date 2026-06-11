#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    long long n,i,b,mn[100010];
    pair<long long,long long> a[100010];
    long long ans[100010];
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> b;
        a[i] = make_pair(b,i);
        ans[i] = 0;
    }
    a[0] = make_pair(0,0);
    sort(a,a+n+1);
    mn[n+1] = 1000010;
    for(i=n;i>=0;i--){
        mn[i] = min(a[i].second,mn[i+1]);
    }

    for(i=n;i>=1;i--){
            ans[mn[i]] += (n+1-i)*(a[i].first-a[i-1].first);
    }

    for(i=1;i<=n;i++){
        cout << ans[i] << endl;
    }
}