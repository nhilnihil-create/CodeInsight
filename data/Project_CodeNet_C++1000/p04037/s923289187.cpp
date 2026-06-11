#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxn=100000+10;
int a[maxn];
bool czy;
int i,j,k,l,t,n,m;
int main(){
    scanf("%d",&n);
    fo(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    fo(i,1,n)
        if (i+1>a[i+1]){
            if ((a[i]-i)%2==1){
                czy=1;
                break;
            }
            czy=0;
            fo(j,i+1,n)
                if (a[j]==i) czy^=1;else break;
            break;
        }
    if (czy) printf("First\n");else printf("Second\n");
}