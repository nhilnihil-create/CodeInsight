#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int mn = n, mx=0;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        mx = max(a[i], mx);
        mn = min(a[i], mn);
    }

    if (mx-mn>1) {
        cout<<"No"<<endl;
        return 0;
    }
    else if (mx-mn == 1) {
        int kom = 0, beshi = 0;
        for (int i=1; i<=n; i++)
            if (a[i] == mn)     kom++;
            else                beshi++;

        int unq = kom;
        int prs = beshi/2;

//        cout<<unq<<" "<<prs<<endl;

        if (unq < mx && mx <= unq+prs)    cout<<"Yes"<<endl;
        else                            cout<<"No"<<endl;
    }
    else {
        if (mn == n-1)  cout<<"Yes"<<endl;
        else {
            if (mn <= n/2)  cout<<"Yes"<<endl;
            else            cout<<"No"<<endl;
        }
    }
//    main();
}

