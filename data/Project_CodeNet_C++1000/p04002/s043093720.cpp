#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=112345;
int h,w,n,a[maxn],b[maxn];
long long num[10];
set<pii> st,vis;
inline void add(int x,int y) {
    int cnt=0;
    for (int i=x-1;i<=x+1;++i)
        for (int j=y-1;j<=y+1;++j)
            if (st.find(pii(i,j))!=st.end())
                ++cnt;
    ++num[cnt];
}
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    for (int i=1;i<=n;++i) {
        scanf("%d%d",&a[i],&b[i]);
        st.insert(pii(a[i],b[i]));
    }
    for (int i=1;i<=n;++i) {
        int x=a[i],y=b[i];
        for (int j=x-1;j<=x+1;++j)
            for (int k=y-1;k<=y+1;++k) {
                if (j<=1||j>=h||k<=1||k>=w) continue;
                if (vis.find(pii(j,k))!=vis.end()) continue;
                vis.insert(pii(j,k));
                add(j,k);
            }
    }
    int sum=0;
    for (int i=0;i<10;++i) sum+=num[i];
    num[0]+=1ll*(h-2)*(w-2)-sum;
    for (int i=0;i<10;++i)
        cout<<num[i]<<endl;
    return 0;
}
