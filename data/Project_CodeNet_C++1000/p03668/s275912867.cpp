#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <list>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const LL mod=1e9+7;
const double PI=acos(-1);
const double EPS=1e-6;
const int INF=0x3f3f3f3f;
inline int readint(){int sum=0;char c=getchar();bool f=0;while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}if(f) return -sum;return sum;}
inline LL readLL(){LL sum=0;char c=getchar();bool f=0;while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}if(f) return -sum;return sum;}

vector<int> E[100005];

int dfs(int pos,int fa){
    int ans=0;
    for(int i=0;i<E[pos].size();i++){
        if(E[pos][i]==fa) continue;
        ans^=(dfs(E[pos][i],pos)+1);
    }
    return ans;
}

int main(){//ios_base::sync_with_stdio(0);cin.tie(0);
    int n=readint();
    for(int i=1;i<n;i++){
        int u=readint(),v=readint();
        E[u].push_back(v);
        E[v].push_back(u);
    }
    if(dfs(1,0)) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}

//cout.setf(ios::fixed);
//cout<<fixed<<setprecision(10)<<s<<endl;
