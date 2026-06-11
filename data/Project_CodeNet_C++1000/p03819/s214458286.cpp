/*Program from Luvwgyx*/
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,cnt;
vector<int >v[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(int x){print(x);puts("");}
struct Binary_Index_Tree{
    int tree[maxn];
    void change(int x,int v){for(;x<=m;x+=(x&(-x)))tree[x]+=v;}
    int  query (int x){int ret=0;for(;x;x-=(x&(-x)))ret+=tree[x];return ret;}
}T;
int main(){
    cnt=n=read();m=read();
    for(int i=1;i<=n;i++){
        int l=read(),r=read();
        v[r-l+1].push_back(l);
    }
    for(int i=1;i<=m;i++){
        int ans=cnt;
        for(int j=i;j<=m;j+=i)ans+=T.query(j);
        for(vector<int > :: iterator it=v[i].begin();it!=v[i].end();it++)
            T.change(*it,1),T.change(*it+i,-1),--cnt;
        write(ans);
    }
    return 0;
}
