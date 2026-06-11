#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
int n, m, Col[101000], cnt;
bool DFS(int a, int c){
    Col[a] = c;
    cnt++;
    int i;
    bool res = true;
    for(i=0;i<E[a].size();i++){
        if(Col[E[a][i]]){
            if(Col[E[a][i]] + c != 3)res = false;
        }
        else{
            if(!DFS(E[a][i], 3 - c))res = false;
        }
    }
    return res;
}
int main(){
    int i, a, b, c1 = 0, c2 = 0, c3 = 0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(!Col[i]){
            cnt = 0;
            bool tp = DFS(i,1);
            if(cnt == 1)c1++;
            else if(tp)c2++;
            else c3++;
        }
    }
    printf("%lld\n",1ll*c1*c1 + 2ll*c1*(n-c1) + 1ll*(c2+c3)*(c2+c3) + 1ll*c2*c2);
}