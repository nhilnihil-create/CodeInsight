#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <set>
#include <unordered_map>
using namespace std;

int n,m;
//n个盒子，m次操作
vector<int> qiu,hong;
int main(){
    scanf("%d%d",&n,&m);
    qiu.resize(n+1);
    hong.resize(n+1);
    for(int i=1;i<=n;i++){
        qiu[i]=1;
    }
    hong[1]=1;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(hong[a]!=0){
            hong[b]=1;
        }
        qiu[a]--;
        qiu[b]++;
        if(qiu[a]==0){
            hong[a]=0;
        }
        if(qiu[b]==0){
            hong[b]=0;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(qiu[i]!=0 && hong[i]!=0){
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
