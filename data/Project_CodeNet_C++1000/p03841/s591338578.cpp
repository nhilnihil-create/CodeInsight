#include <bits/stdc++.h>
#define ll long long
#define fi first
#define sec second
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define pii pair<int,int>
#define sit set<int>:: iterator
#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;


const int MAXN=510;

int x[MAXN],a[MAXN*MAXN],cnt[MAXN];
vector<pii > V;

int main(){
    int n;
    scanf("%d",&n);

    rep(i,0,n){
        scanf("%d",&x[i]);
        a[x[i]]=i+1;cnt[i+1]++;
        V.pb({x[i],i+1});
    }

    sort(V.begin(),V.end());

    int last=0,j=0;

    rep(i,1,n*n+1){
        if(a[i]){
            if(cnt[a[i]]!=a[i]){
                printf("No\n");
                return 0;
            }
            continue;
        }
        while(j<n){
            if(cnt[V[j].sec]<V[j].sec){
                a[i]=V[j].sec;
                cnt[V[j].sec]++;
                break;
            }
            j++;
        }
        if(j==n){
            while(last<n){
                if(cnt[V[last].sec]<n&&V[last].fi<i){
                    a[i]=V[last].sec;
                    cnt[a[i]]++;
                    break;
                }
                last++;
            }
            if(last==n){
                printf("No\n");
                return 0;
            }
        }
    }

    printf("Yes\n");
    rep(i,1,n*n+1)
        printf("%d ",a[i]);
    printf("\n");

}
