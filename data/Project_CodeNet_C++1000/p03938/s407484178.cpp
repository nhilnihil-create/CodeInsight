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

int p[20000];
int a[20000];
int b[20000];
int main(void){
    int n; cin >> n; for(int i = 0;i < n;i++){int a; cin >> a; a--; p[a] = i;}
    a[0] = 1; b[0] = 1000000000;
    for(int i = 1;i < n;i++){
        if(p[i] - p[i-1] > 0){
            a[i] = a[i-1] + 1 + p[i] - p[i-1];
            b[i] = b[i-1] - 1;
        }else{
            a[i] = a[i-1] + 1;
            b[i] = b[i-1] - 1 + p[i] - p[i-1];
        }
    }
    printf("%d", a[0]); for(int i = 1;i < n;i++)printf(" %d", a[i]);
    printf("\n");
    printf("%d", b[0]); for(int i = 1;i < n;i++)printf(" %d", b[i]);
    printf("\n");
 	return 0;
}
