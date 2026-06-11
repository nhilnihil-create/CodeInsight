#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
ll MAX(ll a,ll b,ll c){return max(a,max(b,c));}
ll MIN(ll a,ll b,ll c){return min(a,min(b,c));}
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
int main(){
    int n;
    cin >> n;
    cout << n*(n+1)/2 << endl;
}