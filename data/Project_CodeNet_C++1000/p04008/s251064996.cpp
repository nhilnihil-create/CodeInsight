#include <bits/stdc++.h>
using namespace std;

vector<int> adjl[100005];
bool visited[100005];
int arr[100005];
int n,k;
int ans = 0;

int func(int node){
    if (adjl[node].size()==0){
        return 1;
    }
    int maxf = 0;
    for (int x : adjl[node]){
        maxf = max(maxf,func(x));
    }
    maxf++;
    if (maxf==k && arr[node]!=1){
        //printf("node %d chosen\n",node);
        ans++;
        return 0;
    }
    return maxf;
}

int main(){
    scanf("%d%d",&n,&k);
    for (int x = 1; x<=n; x++){
        scanf("%d",&arr[x]);
    }
    if (k==1){
        int an = 0;
        for (int x = 1; x<=n; x++){
            if (arr[x]!=1) an++;
        }
        printf("%d",an);
        return 0;
    }
    if (arr[1]!=1) {
        ans++;
        arr[1] = 1;
    }
    for (int x = 2; x<=n; x++){
        adjl[arr[x]].push_back(x);
    }
    func(1);
    printf("%d",ans);


}



