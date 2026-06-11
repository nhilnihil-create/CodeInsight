#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int root;
int arr[100010];
int parent[100010];
vector<int>nodes[100010];

void maketree(int x){
    for(int y:nodes[x]){
        if(y==parent[x])continue;
        parent[y]=x;
        maketree(y);
    }
}

bool f(int x){
    if(nodes[x].size()==1)return true;
    ll sum=0;
    ll maxi=0;
    for(int y:nodes[x]){
        if(y==parent[x])continue;
        if(!f(y))return false;
        sum+=arr[y];
        maxi=max(maxi,(ll)arr[y]);
    }
    if(arr[x]>sum)return false;
    arr[x]-=sum-arr[x];
    if(arr[x]<0)return false;
    if(arr[x]<maxi-(sum-maxi))return false;
    //printf("%d:%d\n",x,arr[x]);
    return true;
}

int main() {
    //freopen("hi.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    if(n==2){
        if(arr[1]==arr[2])printf("YES");
        else printf("NO");
        return 0;
    }
    int a,b;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(nodes[i].size()>1){
            root=i;
            break;
        }
    }
    maketree(root);
    if(!f(root) || arr[root]!=0){
        printf("NO");
    }
    else{
        printf("YES");
    }
}
