#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;

int a[maxn][maxn],h,w,H,W;
long long total;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>H>>W>>h>>w;
    for (int i=1;i<=H;i++)
        for (int j=1;j<=W;j++)
            a[i][j]=3999;
    for (int i=h;i<=H;i+=h)
        for (int j=w;j<=W;j+=w)
            a[i][j]=-3999*(h*w-1)-1;
    for (int i=1;i<=H;i++)
        for (int j=1;j<=W;j++)
            total += a[i][j];
    if (total<0) cout<<"No"<<endl;
    else {
        cout<<"Yes"<<endl;
        for (int i=1;i<=H;i++) {
            for (int j=1;j<=W;j++) cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
}
