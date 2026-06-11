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


int main(){
    int n;
    cin>>n;
    int ans=n;
    vector<int> num(MAX_N,0);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num[a]++;
    }
    int m=0;
    bool f=false;
    for(int i=1;i<=MAX_N;i++){
        if(num[i]>0) m+=num[i]-1;
        if(num[i]>0 && num[i]%2==0) f=!f;
    }
    ans-=m;
    if(f) ans--;
    cout<<ans<<endl;
    

}