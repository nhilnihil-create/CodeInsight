//http://mujin-pc-2017.contest.atcoder.jp/tasks/mujin_pc_2017_a

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int base = (int)1e9+7;

int n,ans=1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
   // freopen("in.txt","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        if (x<2*i-1) {
            ans = (1ll*ans*i)%base;
            i--;
            n--;
        }
    }
    for (int i=1;i<=n;i++) ans = (1ll*ans*i)%base;
    cout<<ans;
}
