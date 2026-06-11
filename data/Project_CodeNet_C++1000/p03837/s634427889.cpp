#include <iostream>
#include <vector>
#include <limits>

using namespace std;
struct Edge{
    int a;
    int b;
    double c;
};
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<double>> dista(n, vector<double>(n, numeric_limits<double>::infinity()));
    vector<Edge> edge(m);
    int a, b;
    double c;
    for(int i=0;i<m;++i){
        cin >> a >> b >> c;
        --a; --b;
        edge[i].a = a;
        edge[i].b = b;
        edge[i].c = c;
        dista[a][b] = c;
        dista[b][a] = c;
    }
    for(int i=0;i<n;++i){
        dista[i][i]=0;
    }
    double d;
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(dista[i][j]>(d=dista[i][k]+dista[k][j])){
                    dista[i][j]=d;
                }
            }
        }
    }
    int  count=m;
    for(int k=0;k<m;++k){
        bool flag=false;
        for(int i=0;i<n;++i){
            if(dista[i][edge[k].a]+edge[k].c==dista[i][edge[k].b])
                flag=true;
        }
        if(flag)
            --count;
    }
    cout <<  count;
    return 0;
}