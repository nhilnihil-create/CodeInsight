#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 200005
int main(){
    int n;
    scanf("%d",&n);
    int ans=0;
    int a[100005];
    map<int,int> loc;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        loc[a[i]]=i;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(loc[a[i]]%2!=i%2){
            ans++;
        }
    }
    printf("%d\n",ans/2);
}