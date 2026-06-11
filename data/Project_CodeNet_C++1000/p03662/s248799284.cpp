#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;

int main(){
    int N;
    cin >> N;
    vector<int> v[N];
    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> qu;
    int st[N];
    memset(st,0,sizeof(st));
    st[0]=1;st[N-1]=-1;
    qu.push(0);
    qu.push(N-1);
    while(qu.size()){
        int s=qu.front();
        qu.pop();
        for(int i=0;i<v[s].size();i++){
            if(st[v[s][i]]==0){
                if(st[s]==1){
                    qu.push(v[s][i]);
                    st[v[s][i]]=1;
                }
                else if(st[s]=-1){
                    qu.push(v[s][i]);
                    st[v[s][i]]=-1;
                }
            }
        }
    }
    int fennec=0,snuke=0;
    for(int i=0;i<N;i++){
        if(st[i]==1) fennec++;
        else snuke++;
    }
    if(fennec>snuke) puts("Fennec");
    else puts("Snuke");
    return 0;
}