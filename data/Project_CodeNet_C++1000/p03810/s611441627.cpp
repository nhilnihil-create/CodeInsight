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
#define MXN 300000
int a[100005];
int go(int n){
    LL tot=0;
    vector<int> v;
    for(int i = 0;i<n;i++){
        tot+=a[i];
        if(a[i]&1)v.pb(i);
    }
    if((tot-n)&1){
        return 1;
    }
    if(v.size()!=1||a[v[0]]==1){
        return 0;
    }
    a[v[0]]--;
    int gcd=0;
    for(int i = 0;i<n;i++)
        gcd=__gcd(a[i],gcd);
    for(int i = 0;i<n;i++)
        a[i]/=gcd;
    return 1-go(n);
}
int main(){
    int n;
    scanf("%d",&n);

    LL tot=0;
    vector<int> v;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
       // if(a[i]&1)v.pb(i);
      //  tot+=a[i];
    }
    if(go(n)){
        printf("First\n");
    }
    else{
        printf("Second\n");
    }
}
/*
5 4
8 1 0 3 0
0 0 1 3 8
1
*/