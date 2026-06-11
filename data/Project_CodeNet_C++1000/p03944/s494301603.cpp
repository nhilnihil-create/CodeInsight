#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int W, H, N;
void func()
{
    cin>>W>>H>>N;
    int x[N], y[N], a[N];
    rep(i, 0, N) {
        cin>>x[i]>>y[i]>>a[i];
    }
    int ans=W*H;
    int p1=0, p2=W, p3=0, p4=H;
    rep(i, 0, N) {
        if (a[i]==1) {
            p1=(x[i]>p1)?x[i]:p1;
        }
        else if (a[i]==2) {
            p2=(x[i]<p2)?x[i]:p2;
        }
        else if (a[i]==3) {
            p3=(y[i]>p3)?y[i]:p3;
        }
        else if (a[i]==4) {
            p4=(y[i]<p4)?y[i]:p4;
        }
        if (p2<p1 || p4<p3) {
            ans=0;
        }
        else {
            ans=(p2-p1)*(p4-p3);
        }
    }
    cout<<ans<<endl;
}
int main()
{
    func();
}