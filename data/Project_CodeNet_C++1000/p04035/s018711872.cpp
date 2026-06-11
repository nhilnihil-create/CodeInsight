#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+8;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, L;
    cin>>n>>L;

    for (int i=1; i<=n; i++)    cin>>a[i];

    int mx = 0, mxid;
    for (int i=1; i<=n; i++)
        if (a[i+1]+a[i] > mx) {
            mx = a[i] + a[i+1];
            mxid = i;
        }

    if (mx < L)    {
        cout<<"Impossible"<<endl;
        return 0;
    }

    cout<<"Possible"<<endl;
    for (int i=1; i<mxid; i++)  cout<<i<<"\n";
    for (int i=n-1; i>mxid; i--)  cout<<i<<"\n";
    cout<<mxid<<endl;
}
