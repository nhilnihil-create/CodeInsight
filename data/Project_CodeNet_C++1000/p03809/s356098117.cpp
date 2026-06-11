
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define long long long

using namespace std;

vector<int> vec[100003], chi[100003];
bool visited[100003];
long A[100003];
int root = 0;

void dfs(int u)
{
    visited[u] = 1;
    long sum = 0;
    long mx = 0;
    for(int v : vec[u])
    {
        if(visited[v]) continue;
        chi[u].push_back(v);
        dfs(v);
        sum += A[v];
        mx = max(mx, A[v]);
    }
//    printf("%d %d %d\n", u, A[u], sum);
    
    if(chi[u].size() == 0)
    {
        return;
    }
    
    if(sum < A[u])
    {
        printf("NO\n");
        exit(0);
    }
    if(sum > 2*A[u])
    {
        printf("NO\n");
        exit(0);
    }
    
    long dif = sum-A[u];
     A[u] -= dif;
    if(sum-mx < dif)
    {
        printf("NO\n");
        exit(0);
    }
    
}

int main()
{
//        freopen("input.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &A[i]);
    
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    if(n == 2)
    {
        if(A[1] == A[2]) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(root == 0 && vec[i].size() != 1)
            root = i;
    }
    
    dfs(root);
    
//    printf("ROOT : %d %lld\n", root, A[root]);
    
    if(A[root]) printf("NO\n");
    else printf("YES\n");
}
