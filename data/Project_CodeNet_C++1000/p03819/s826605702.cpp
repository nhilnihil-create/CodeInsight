#include <cstdio>
#include <vector>
using namespace std;
#define low(i) ((i)&(-(i)))
 
const int maxm=1e5+5;
 
int n,m,cnt;
vector<int>range[maxm];
vector<int>::iterator it;
 
int read() {
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return x*f;
}
 
struct TreeArray {
    int c[maxm];
 
    void change(int pos,int v) {
        for(int i=pos;i<=m;i+=low(i))
            c[i]+=v;
    }
 
    int query(int pos) {
        int res=0;
        for(int i=pos;i;i-=low(i))
            res+=c[i];
        return res;
    }
}T;
 
int main() {
    cnt=n=read(),m=read();
    for(int i=1;i<=n;i++) {
        int l=read(),r=read();
        range[r-l+1].push_back(l);
    }
    for(int i=1;i<=m;i++) {
        int ans=cnt;
        for(int pos=i;pos<=m;pos+=i)
            ans+=T.query(pos);
        for(it=range[i].begin();it!=range[i].end();it++)
            T.change(*it,1),T.change((*it)+i,-1),cnt--;
        printf("%d\n",ans);
    }
    return 0;
}
