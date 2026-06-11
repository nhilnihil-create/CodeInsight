#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //ビット演算(最下位ビットが1のとき)
        x = (x * x) % MOD;
        n >>= 1; //右シフト(n = n >> 1)
    }
    return res;
}



int main(){
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> ans;
    int sum = 0;
    for (int i = 1; i <= N; i++){
        sum += i;
        ans.push_back(i);

        if (sum > N){
            ans[sum - N - 1] = -1;
            break;
        }
        if (sum == N){
            break;
        } 
    }
    for (auto i : ans){
        if (i != -1) cout << i << endl;
    }

    return 0;
} 
