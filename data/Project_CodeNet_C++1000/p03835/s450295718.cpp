#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
using ll = long long ;
const int INF = 1001001001;
using namespace std;

int main() {

    int k,s ;
    cin >> k >> s  ;
    int ans = 0 ;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
        //   for()
            int z = s-i-j ;
            if(z>=0 && z<=k)ans++ ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}