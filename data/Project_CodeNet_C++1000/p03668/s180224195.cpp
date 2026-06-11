#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 6;

vector<int> edg[MAX_N];
bool visit[MAX_N];

int dfs(int id) {
    visit[id]=1;
    int ret=0;
    for (int i:edg[id]) {
        if (!visit[i]) ret ^= (dfs(i)+1);
    }
    return ret;
}

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1;n>i;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    int ret=dfs(1);
    if (ret==0) puts("Bob");
    else puts("Alice");
}

