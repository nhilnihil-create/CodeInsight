#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define MAXN 200005
#define INF 999999999999999LL
using namespace std;
ll n,a[MAXN],bl,br,bm,bo,cls,ans;
bool ab[MAXN];
int main(){
    cin>>n; n=2*n-1;
    for (int i=0; i<n; i++) scanf("%lld",&a[i]);

    bl=1; br=n;
    while(bl<=br){
        bm=(bl+br)/2;

        for (int i=0; i<n; i++)
            if (a[i]>=bm) ab[i]=1; else ab[i]=0;
        
        cls=INF; bo=ab[0];
        for (int i=0; i<n; i++){
            if (i<n-1 && ab[i]==ab[i+1]){
                if (abs(n/2-i)<cls) { cls=abs(n/2-i); bo=ab[i]; }
                
                while(i<n-1 && ab[i]==ab[i+1]) i++;

                if (abs(n/2-i)<cls) { cls=abs(n/2-i); bo=ab[i]; }
            }
        }

        if (bo) { ans=bm; bl=bm+1; }
        else br=bm-1;
    }

    cout<<ans<<endl;
}