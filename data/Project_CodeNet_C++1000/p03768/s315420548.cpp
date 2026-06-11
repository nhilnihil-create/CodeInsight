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
using namespace std;

int n,m;
vector<vector<int> > g;
vector<int> col;

int main(int argc, char* argv[])
{
    scanf("%d%d", &n, &m);
    g.resize(n);
    col.resize(n);
    int i;
    for(i=0; i<n; i++) col[i]=0;

    for(i=0; i<m; i++) {
        int aa, bb;
        scanf("%d%d", &aa, &bb);
        g[aa-1].push_back(bb-1);
        g[bb-1].push_back(aa-1);
    }

    int q;
    scanf("%d", &q);
    vector<int> v(q), d(q), c(q);

    for(i=0; i<q; i++) {
        scanf("%d%d%d", &v[i], &d[i], &c[i]);
        v[i]--;
    }
    vector<int> vis(n*11,-1);
    for(i=q-1; i>=0; i--) {
        queue<pair<int, int> > que;   // vertex, dist
        que.push( make_pair(v[i], d[i]) );
        
        while( !que.empty() ) {
            auto tmp=que.front();
            que.pop();

            int curr = tmp.first;
            int dist = tmp.second;
            if(col[curr]<1) col[curr]=c[i];

            if(dist==0) continue;

            int k;
            int siz=g[curr].size();
            for(k=0; k<siz; k++) {
                int next = g[curr][k];

                int new_dist = dist-1;
                int p;
                for(p=10; p>=new_dist; p--) {
                    if(vis[next*11+p]>=0) {
                        break;
                    }
                }
                if(p>=new_dist) {
                    continue;
                }
                vis[next*11+new_dist]=1;

                que.push( make_pair( next, new_dist) );
            }
        }
    }

    for(i=0; i<n; i++) {
        printf("%d\n", col[i]);
    }
    
    return 0;
}
