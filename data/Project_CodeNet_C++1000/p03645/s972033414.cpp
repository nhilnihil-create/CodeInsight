#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;
bool from1[200100];
bool ton[200100];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        if(a==0){
            from1[b]=true;
        }
        if(b==0){
            from1[a]=true;
        }
        if(a==n-1){
            ton[b]=true;
        }
        if(b==n-1){
            ton[a]=true;
        }
    }
    for(int i=1;i<n-1;i++){
        if(from1[i] && ton[i]){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;

}