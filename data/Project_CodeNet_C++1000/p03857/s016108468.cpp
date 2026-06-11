#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int N=200010;
vector <int> q[N];
int fa[N],id[N],ans[N],L[N],R[N],op[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
inline bool cmp(const int &x,const int &y) {return fa[x]<fa[y];}
inline int query(vector <int> &v,int x) {
    int l=0,r=v.size()-1;
    while(l<=r) {
	int mid=(l+r)>>1;
	if(v[mid]<=x) l=mid+1;
	else r=mid-1;
    }
    return r;
}
int main() {
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=k;i++) {
	int x=find(gi()),y=find(gi());
	if(x!=y) fa[x]=y;
    }
    for(int i=1;i<=n;i++) find(i),op[i]=i;
    sort(op+1,op+1+n,cmp);
    for(int i=1;i<=n;i++) id[op[i]]=i;
    for(int i=1,j;i<=n;i++) {
	if(fa[op[i]]!=fa[op[i-1]]) j=i;
	L[i]=j;
    }
    for(int i=n,j;i;i--) {
	if(fa[op[i]]!=fa[op[i+1]]) j=i;
	R[i]=j;
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) {
	int x=find(gi()),y=find(gi());
	if(x!=y) fa[x]=y;
    }
    for(int i=1;i<=n;i++) q[find(i)].push_back(id[i]);
    for(int i=1;i<=n;i++) sort(q[i].begin(),q[i].end());
    for(int i=1;i<=n;i++) {
	int x=find(i);
	printf("%d ",query(q[x],R[id[i]])-query(q[x],L[id[i]]-1));
    }
    return 0;
}