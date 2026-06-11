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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
int a[305][305];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int Max=n,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int index[305];
        fill(index,index+n,1);
        int ok=1;
        vector<int> v[305];
        int ook[305];
        fill(ook,ook+m+1,1);
        for(int i = 0;i<n;i++)v[a[i][0]].pb(i);
        while(true){
            int out=1;
            for(int i = 1;i<=m;i++){
            //    printf("%d\n",v[i].size());
                if(v[i].size()>mid){
                    out=0;
                    ook[i]=0;
                    for(auto it:v[i]){
                        while(!ook[a[it][index[it]]]&&index[it]!=m){
                            index[it]++;
                        }
                      //  printf("?%d\n",a[it][index[it]]);
                        if(index[it]!=m)
                        v[a[it][index[it]++]].pb(it);
                        else ok=0;
                    }
                  //  printf("%d %d\n",i,mid);
                    v[i].clear();
                }
            }
            if(out)break;
        }
        if(ok)Max=mid;
        else Min=mid;
    }
    printf("%d\n",Max);
}