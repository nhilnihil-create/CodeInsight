#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;

int main(){
    int n, cnt=0; cin >> n;
    int num[100000] = {0};
    REP(i, n){
        int a; cin >> a;
        num[a-1]++;
    }
    REP(i, 100000){
        if(num[i]) cnt++;
    }
    cout << (cnt%2 ? cnt : cnt-1) << endl;
    return 0;
    
}
