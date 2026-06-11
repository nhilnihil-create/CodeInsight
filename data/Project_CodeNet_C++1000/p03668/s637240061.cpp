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
#define pow POW
vector<int> v[100005];
int dfs(int x,int f){
    int res=0;
    for(auto it:v[x]){
        if(it!=f){
            res=res^(dfs(it,x)+1);
        }
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i= 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    if(dfs(1,0))printf("Alice\n");
    else printf("Bob\n");
}
/*
7 7
1 1 4 7
1 1 2 5
1 2 6 7
1 1 5 8
1 1 3 6
1 3 7 5
0 1 6 7
d-1 2-d 3-d=d
d-1 2-d 3-d 4-d
12 02 0 1
a1 a2 a3 a4
a1-a2-a3-a4
a1-a2-a3+a4
a1-a2+a3-a4
a1-a2+a3+a4
a1-a2-a3+a4
a1-a2+a3-a4
*/
//a+a+1=10a+1
//3a+2=10a+2