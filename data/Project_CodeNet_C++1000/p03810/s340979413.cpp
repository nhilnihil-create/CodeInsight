#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int n,a[N];
int gcd(int x,int y){
    if(!y)
        return x;
    return gcd(y,x%y);
}
bool dfs(int a[]){
    if(n==1)
        return false;
    int cnte=0,cnto=0,poso=-1;
    for(int i=1;i<=n;i++)
        if(a[i]%2)
            cnto++,poso=i;
        else
            cnte++;
    if(cnte%2)
        return true;
    else if(cnto>1)
        return false;
    else{
        if(a[poso]==1){
            ll tmp=0;
            for(int i=1;i<=n;i++)
                tmp+=a[i]-1;
            return tmp%2;
        }
        a[poso]--;
        int g=a[1];
        for(int i=2;i<=n;i++)
            g=gcd(g,a[i]);
        for(int i=1;i<=n;i++)
            a[i]/=g;
        return dfs(a)^1;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    puts(dfs(a)?"First":"Second");
}
