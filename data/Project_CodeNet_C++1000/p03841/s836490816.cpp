//by Sshwy
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)

namespace RA{
    int rnd(int p){return 1ll*rand()*rand()%p;}
    int rnd(int L,int R){return rnd(R-L+1)+L;}
}
const int N=505;
int n;
int a[N];
int b[N*N];
int c[N],ok[N]; // counter of usage
vector<int> v;
int main(){
    scanf("%d",&n);
    FOR(i,1,n)scanf("%d",&a[i]),b[a[i]]=i;
    FOR(i,1,n*n)if(b[i])v.pb(b[i]);
    FOR(i,1,n*n){
        if(b[i]){
            if(c[b[i]]+1==b[i]) c[b[i]]++,ok[b[i]]=1;
            else return puts("No"),0;
        }else {
            bool flag=0;
            for(int j:v)if(!ok[j] && c[j]<j-1){ ++c[j],b[i]=j,flag=1;break; }
            if(flag==0)for(int j:v)if(ok[j] && c[j]<n){ ++c[j],b[i]=j,flag=1;break; }
            if(flag==0)return puts("No"),0;
        }
    }
    puts("Yes");
    FOR(i,1,n*n)printf("%d%c",b[i]," \n"[i==n*n]);
    return 0;
}
