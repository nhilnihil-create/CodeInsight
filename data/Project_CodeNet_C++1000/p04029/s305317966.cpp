#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define INF 100000000;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const double eps = 1.0e-14;
const double PI = (acos(-1));
int main(){
    int n;
    cin >> n;
    int ans = 0;
    rep(i,n){
        ans += i + 1;
    }
    cout << ans << endl;
}