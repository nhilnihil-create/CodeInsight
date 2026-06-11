#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;

    if (k == 1 || k==2*n-1) {
        cout<<"No"<<endl;
        return 0;
    }

    if (n == k) {
        cout<<"Yes"<<endl;
        for (int i=1; i<2*n; i++)    cout<<i<<"\n";
        cout<<endl;
    }
    else {
        vector<int> ans(2*n), done(2*n);
        ans[n] = k;
        if (k > n)  ans[n+1] = 2*n-1, ans[n+2] = k-1, ans[n-1] = k-2;
        else        ans[n+1] = 1, ans[n+2] = k+1, ans[n-1] = k+2;

        for (int i=n-1; i<=n+2; i++)    done[ans[i]] = 1;

        int cur = 1;
        for (int i=1; i<2*n; i++) {
            if (ans[i]) continue;
            while(done[cur])    cur++;
            ans[i] = cur;
            done[cur]=1;
        }
        cout<<"Yes"<<endl;
        for (int i=1; i<2*n; i++)   cout<<ans[i]<<"\n";
        cout<<endl;
    }
}
