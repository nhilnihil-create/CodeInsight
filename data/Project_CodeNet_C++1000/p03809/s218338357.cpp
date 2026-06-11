#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
vector<int> adjl[100005];
vector<int> children[100005];

void dfs(int node, int parent){
    for (int x : adjl[node]){
        if (x==parent) continue;
        children[node].push_back(x);
        dfs(x,node);
    }
}


int func(int node){
if (children[node].size()==0){
    return arr[node];
}
if (children[node].size()==1){
    int t = func(children[node][0]);
    if (t==-1) return -1;
    if (t==arr[node]) return t;
    else return -1;
}
if (children[node].size()==2){
    int a = func(children[node][0]);
    int b = func(children[node][1]);
    if (a==-1||b==-1) return -1;
    if (arr[node]<max(a,b)) return -1;
    if (arr[node]>a+b) return -1;
    return 2*arr[node]-a-b;
}
else{
    vector<int> v;
    int sum = 0;
    int mx = -1;
    for (int x : children[node]){
        int t = func(x);
        if (t==-1) return -1;
        sum += t;
        mx = max(mx,t);
        v.push_back(t);
    }
    if (arr[node]<mx)return -1;
    if (arr[node]<(sum+1)/2) return -1;
    if (arr[node]>sum) return -1;
    return 2*arr[node]-sum;

}
}

int main(){
scanf("%d",&n);
for (int x = 0; x<n; x++){
    scanf("%d",&arr[x]);
}
for (int x = 0; x<n-1; x++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
}
if (n==2){
    printf(arr[0]==arr[1]?"YES":"NO");
    return 0;
}
int root = -1;
for (int x = 0; x<n; x++){
    if (adjl[x].size()>1){
        root = x;
    }
}
dfs(root,-1);
printf(func(root)==0?"YES":"NO");

}
