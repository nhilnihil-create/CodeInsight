#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<double, double> Pdd;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;

const ll mod = 1e9+7;
const int INF = 2e9;
const double epsilon = 1e-7;
const double PI = 3.1415926535;

ll ma(ll x, ll y){
    if(x>y)return x;
    return y;
}
int p[100001];
int main(void){
    int n; cin >> n; int ans = 0; int flag = -1;
    for(int i = 1;i <= n;i++)cin >> p[i];
    for(int i = 1;i <= n;i++){
        if(p[i] == i){
            flag*=-1;
            if(flag == -1)ans++;
        }else{
            if(flag == 1){flag = -1;ans++;}
        }
    }
    if(flag == 1)ans++;
    cout << ans << endl;
 	return 0;
}
