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
typedef pair<int,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999999;



int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> b;
    for(int i=0;i<n;i++){
        if(i%2==0){
            b.push_back(a[i]);
        }
    }
    reverse(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(i%2==1){
            b.push_back(a[i]);
        }
    }
    if(n%2==0) reverse(b.begin(),b.end());
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}