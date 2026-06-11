#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;

vector < int > v[N], put;
int n, bio[N], m;

void dfs(int x){
    bio[x] = 1;
    put.push_back(x);
    for(int y : v[x]){
        if(bio[y]) continue;
        dfs(y);
        return;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i<m;i++){
        int x, y;scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    reverse(put.begin(), put.end());
    for(int y : v[1]){
        if(bio[y]) continue;
        dfs(y);
        break;
    }
    printf("%d\n", put.size());
    for(int x : put)
        printf("%d ", x);
    printf("\n");

}
