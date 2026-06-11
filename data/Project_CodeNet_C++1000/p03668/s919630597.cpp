
#include <stdio.h>
#include <algorithm>
#include <vector>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

using namespace std;

const int N=100010;
int n,x,y;
vector<int> vec[N];

int dfs(int x,int pa) {
    int tmp=0;
    for (int i=0;i<vec[x].size();i++) {
        if (vec[x][i]==pa) continue;
        tmp^=(dfs(vec[x][i],x)+1);
    }
    return tmp;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n-1;i++) {
        scanf("%d%d",&x,&y);
        vec[x].pb(y);
        vec[y].pb(x);
    }
    int res=dfs(1,0);
    if (res==0) printf("Bob\n");
    else printf("Alice\n");
}