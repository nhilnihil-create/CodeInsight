#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
 
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define PI acos(-1.0)
const int N=1e5 + 5;
const int M=1e5 + 5;

vector <int> v[N];
vector < pair < int , int > > qu[N];
int clr[N],foo[N],mp[N]; 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    } 
    int qq;
    cin>>qq;
    for(i=0;i<qq;i++){
        int v,d,c;
        cin>>v>>d>>c;
        mp[i]=c;
        qu[d].pb(mkp(v,i));
    }
    for(i=1;i<=n;i++){
        foo[i]=clr[i]=-1;
    }
    for(j=10;j>=0;j--){
        for(int k=0;k<qu[j].size();k++){
            int x = qu[j][k].fi;
            clr[x] = max(clr[x],qu[j][k].se);
        }
        for(i=1;i<=n;i++) foo[i]=clr[i];
        if(j==0) break;
        for(i=1;i<=n;i++){
            for(int k=0;k<v[i].size();k++){
                int x = v[i][k];
                clr[i] = max(clr[i],foo[x]);
            }
        }

    }
    for(i=1;i<=n;i++){
        if(clr[i]==-1) cout << 0 << endl;
        else cout << mp[clr[i]] << endl;
    }


 
    return 0;
}