#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

int main(int argc, char* argv[])
{
    int n,m;
    scanf("%d%d", &n, &m);

    vector<int> vis(n);
    vector<vector<int> > g(n);
    int i;
    vector<int> v0,v1;
    int prev,curr;
    for(i=0; i<m; i++) {
        int a,b;
        scanf("%d%d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        if(i==0) {
            v0.push_back(a);
            v0.push_back(b);
            vis[a]=vis[b]=1;
            prev=a; curr=b;
        }
    }
    while(1) {
        int siz=g[curr].size();
        for(i=0; i<siz; i++) {
            int next=g[curr][i];
            if(next==prev) continue;
            if(vis[next]) continue;

            v0.push_back(next);
            vis[next]=1;
            prev=curr;
            curr=next;
            break;
        }
        if(i<siz) {
            continue;
        }
        else {
            break;
        }
    }

    curr=v0[0];
    prev=v0[1];
    while(1) {
        int siz=g[curr].size();
        for(i=0; i<siz; i++) {
            int next=g[curr][i];
            if(next==prev) continue;
            if(vis[next]) continue;

            v1.push_back(next);
            vis[next]=1;
            prev=curr;
            curr=next;
            break;
        }
        if(i<siz) {
            continue;
        }
        else {
            break;
        }
    }

    int num=(int)v0.size()+(int)v1.size();
    printf("%d\n", num);
    for(i=0; i<(int)v1.size(); i++) {
        printf("%d ", v1[(int)v1.size()-1-i]+1);
    }
    for(i=0; i<(int)v0.size(); i++) {
        printf("%d ", v0[i]+1);
    }
    printf("\n");

    return 0;
}

