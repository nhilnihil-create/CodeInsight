#include<bits/stdc++.h>
using namespace std;

const int N = 20005;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    for (int i=1; i<=n; i++)    a[i] = i*n, b[i] = (n+1-i)*n;

    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        a[x] += i;
    }

    for (int i=1; i<=n; i++)    cout<<a[i]<<" "; cout<<endl;
    for (int i=1; i<=n; i++)    cout<<b[i]<<" "; cout<<endl;
}
