#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 100000+5;
const int dx[] = {0,0,-1,1,-1,-1,1,1};
const int dy[] = {-1,1,0,0,-1,1,-1,1};
using namespace std;
char str[N];
int res[N];
void cal(int i){
    if(str[i]=='o'&&res[i]==0){
        res[i+1]=res[i-1];
    }
    else if(str[i]=='o'&&res[i]==1){
        res[i+1]=!res[i-1];
    }
    else if(str[i]=='x'&&res[i]==0){
        res[i+1]=!res[i-1];
    }
    else if(str[i]=='x'&&res[i]==1){
        res[i+1]=res[i-1];
    }
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);

    int endd;
    bool flag=false;

    res[1]=0;res[2]=0;
    if(str[1]=='o')
        endd=0;
    else
        endd=1;
    for(int i=2;i<=n;i++)
        cal(i);
    if(res[n]==endd&&res[1]==res[n+1])
        flag=true;

    if(!flag){
        res[1]=0;res[2]=1;
        if(str[1]=='o')
            endd=1;
        else
            endd=0;
        for(int i=2;i<=n;i++)
            cal(i);
        if(res[n]==endd&&res[1]==res[n+1])
            flag=true;
    }
    if(!flag){
        res[1]=1;res[2]=0;
        if(str[1]=='o')
            endd=1;
        else
            endd=0;
        for(int i=2;i<=n;i++)
            cal(i);
        if(res[n]==endd&&res[1]==res[n+1])
            flag=true;

    }
    if(!flag){
        res[1]=1;res[2]=1;
        if(str[1]=='o')
            endd=0;
        else
            endd=1;
        for(int i=2;i<=n;i++)
            cal(i);
        if(res[n]==endd&&res[1]==res[n+1])
            flag=true;
    }

    if(!flag)
        printf("-1\n");
    else{
        for(int i=1;i<=n;i++){
            if(res[i]==0)
                printf("S");
            else
                printf("W");
        }
        printf("\n");
    }

    return 0;
}
