#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n+1);
    repe(i,1,n) cin >> a[i];

    int cnt=0;
    for (int i=1;i<=n;++i){
        int j = a[i];
        if (a[j]==i && a[i] ==j && a[j] !=0 && a[i] !=0) {


            a[j] = a[i] = 0;
            cnt +=1;
        }
    }
    cout << cnt;

    return 0;
}
