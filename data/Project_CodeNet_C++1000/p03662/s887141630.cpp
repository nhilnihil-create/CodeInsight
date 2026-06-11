#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define N 100005
using namespace std;
vector <int> vec[N];
int color[N];
int main(){
    queue <int> que;
    int n , x , y;
    scanf("%d",&n);
    for(int i = 1 ; i < n ; i ++){
        scanf("%d%d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    color[1] = 1 , color[n] = 2;
    int cnt[3] = {0 , 0};
    que.push(1) ;
    que.push(n);
    while(!que.empty()){
        int x = que.front();
        que.pop();
        cnt[color[x]] ++;
 
        for(int i = 0 ; i < vec[x].size() ; i ++){
            int v = vec[x][i];
            if(color[v]) continue;
            color[v] = color[x];
            que.push(v);
        }
    }
    if(cnt[2] >= cnt[1]){
        printf("Snuke\n");
    }else{
        printf("Fennec\n");
    }
 
}