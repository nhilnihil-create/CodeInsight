#include<iostream>
using namespace std;

int main() {
    int inf = 1e5;
    int N, M;
    cin>>N>>M;
    int a, b, c;
    int map[N][N], map1[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(i==j){
                map[i][j] = 0;
                map1[i][j] = 0;
            }
            else{
                map[i][j] = inf;
                map1[i][j] = inf;
            }
        }
    }
    for(int i=0;i<M;++i){
        cin>>a>>b>>c;
        a--;
        b--;
        map[a][b] = c;
        map[b][a] = c;
        map1[a][b] = c;
        map1[b][a] = c;
    }
    int ans = 0;
    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(map[i][j] > map[i][k] + map[k][j]){
                    if(map1[i][j]!=inf & map[i][j]==map1[i][j]){
                        ans++;
                    }
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    cout<<ans/2<<endl;
}
