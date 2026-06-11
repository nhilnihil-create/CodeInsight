#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5;

int n;
int a[MAXN];

int gcd(int x,int y){return !y?x:gcd(y,x%y);}

bool solve(){
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++) (a[i]&1)?cnt1++:cnt0++;
    if(cnt0&1) return 1;
    else if(cnt1>1) return 0;
    else {
        for(int i=1;i<=n;i++)
            if(a[i]&1) {
                if(a[i]==1) return 0;
                else a[i]--;
            }
        int gg=0;
        for(int i=1;i<=n;i++) gg=gcd(gg,a[i]);
        for(int i=1;i<=n;i++) a[i]/=gg;
        return !solve();
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%s",solve()?"First":"Second");
}
