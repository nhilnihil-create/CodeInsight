#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long long int llint;
#define MM 1000000000
#define MOD MM+7
#define pi pair<int,int>
#define pl pair<ll,ll>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
const long double PI = acos(-1);
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int GCD(int x,int y){
    return y ? GCD(y,x%y) : x;
}
int N,M; 
int main(){
    cin >> N >> M;
    ll x[N+1],y[M+1],ans = 0;
    for(int i = 1; i <= N; i++) cin >> x[i];
    for(int i = 1; i <= M; i++) cin >> y[i];
    ll cX = 0, cY = 0;
    for(int i = 1; i <= N; i++){
        cX += (2*i - N - 1)*x[i];
        cX %= MOD;
    }
    for(int i = 1; i <= M; i++){
        cY += (2*i - M - 1)*y[i];
        cY %= MOD;
    }
    //cout << cX << " " << cY << endl;
    ans = cX*cY;
    ans %= MOD;
    //cout << "ans=";
    cout << ans << endl;
}