#include <bits/stdc++.h>
using namespace std;

int n, M, x[100005], nums[100005], p[100005], cnt[100005];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M;
    for(int i=0; i<n; i++) {
        cin >> x[i];
        cnt[x[i]]++;
        nums[x[i]%M]++;
    }
    for(int i=1; i<=100000; i++) {
        p[i%M] += cnt[i]/2;
    }

    for(int i=0; 2*i<=M; i++) {
        if(i==0 || (i==M/2&&M%2==0)) {
            ans += nums[i]/2;
            continue;
        }
        int gap = min(nums[i], nums[M-i]);
        nums[i] -= gap;
        nums[M-i] -= gap;
        ans += gap;
        if(nums[i]==0) ans += min(p[M-i], nums[M-i]/2);
        else if(nums[M-i]==0) ans += min(p[i], nums[i]/2);
    }
    cout << ans << '\n';

    return 0;
}
