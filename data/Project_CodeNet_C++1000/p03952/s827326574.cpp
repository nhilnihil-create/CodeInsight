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

set <int> s;
int main(void){
    //cin.tie(0); ios::sync_with_stdio(false);
    int n, x; cin >> n >> x;
    if(x == 1 || x == 2*n-1){cout << "No" << endl; return 0;}
    cout << "Yes" << endl;
    if(x == 2*n-2){
        for(int i = 1;i <= n-1;i++)cout << i << endl;
        cout << x << endl; cout << x+1 << endl;
        for(int i = n;i <= x-1;i++)cout << i << endl;
    }else{
        int c = 0; int d = 0;
        while(true){
            c++;
            if(c == x-1)c += 4;
            d++; cout << c << endl; if(d == n-2)break;
        }
        cout << x+1 << endl; cout << x << endl; cout << x-1 << endl; cout << x+2 << endl;
        if(n == 3)return 0;
        c = 2*n;
        while(true){
            c--;
            if(c == x+2)c -= 4;
            d++; cout << c << endl; if(d == 2*n-5)break;
        }
    }
 	return 0;
}
