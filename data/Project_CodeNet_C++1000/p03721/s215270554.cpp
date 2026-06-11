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
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    int n;
    ll k;
    cin>>n>>k;
    vector<P> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p.begin(), p.end());
    int i=0;
    int ans;
    while(true){
        k-=p[i].second;
        if(k<=0) break;
        i++;
    }
    cout<<p[i].first<<endl;

}