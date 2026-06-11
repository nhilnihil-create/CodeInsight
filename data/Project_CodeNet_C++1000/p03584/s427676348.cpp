#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int a[maxn],b[maxn];
int fac[32];

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    ll res=0;
    for(int i=0;i<N;i++){
        scanf("%d%d",&a[i],&b[i]);
        if((a[i]|K)==K) res+=b[i];
    }
    for(int i=0;i<=30;i++)
        fac[i]=1<<i;
    for(int i=1;i<=30;i++){
        if(K&fac[i]){
            ll cnt=0;
            int tmp=(K^fac[i])|(fac[i]-1);//把当前位置为0，前面位不变，后面位全为1
            for(int j=0;j<N;j++)
                if((a[j]|tmp)==tmp) cnt+=b[j];
            res=max(res,cnt);
        }
    }
    cout<<res<<endl;
}