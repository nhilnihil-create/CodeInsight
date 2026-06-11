#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
int n;
vector<vector<int> >g;
vector<int> p,q;

void bfs(int a,int pre){
    p[a] = p[pre]+1;
    for(auto x:g[a]){
        if(x!=pre){
            bfs(x,a);
        }
    }
}
void bfs2(int a,int pre){
    q[a] = q[pre]+1;
    for(auto x:g[a]){
        if(x!=pre){
            bfs2(x,a);
        }
    }
}


int main(){
    cin >> n;
    g.resize(n);
    p.resize(n);
    q.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].PB(b);
        g[b].PB(a);
    }
    p[0] = 0;
    q[n-1] = 0;
    bfs(0,0);
    bfs2(n-1,n-1);
    int s = 0;
    int t = 0;
    rep(i,n){
        //cerr << p[i] << " " << q[i] << endl;
        if(p[i]<=q[i]){
            s++;
        }else{
            t++;
        }
    }
    //cerr << s << " " << t << endl;
    if(s>t){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
    return 0;
}