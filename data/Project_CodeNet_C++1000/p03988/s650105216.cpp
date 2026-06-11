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

int a[100];
int c[100];
int main(void){
    int n; cin >> n; for(int i = 0;i < n;i++)cin >> a[i];
    sort(a, a+n);
    if(a[n-1] > n-1 || (a[n-1]+1)/2 > a[0]){printf("Impossible\n"); return 0;}
    fill(c, c+100, 0);
    for(int i = 0;i < n;i++)c[a[i]]++;
    if((a[n-1]%2 == 0 && c[a[0]] != 1) || (a[n-1]%2 == 1) && c[a[0]]!= 2){printf("Impossible\n"); return 0;}
    for(int i = a[0]+1;i <= a[n-1];i++){
        if(c[i]<2){printf("Impossible\n"); return 0;}
    }
    printf("Possible\n");
 	return 0;
}
