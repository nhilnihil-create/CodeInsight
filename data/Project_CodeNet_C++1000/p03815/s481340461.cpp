#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
long long x;
long long solve(){
    long long a = x/11;
    long long ans = 0;
    ans += a * 2;
    x -= a * 11;
    if(x > 0){
        ans += x/7 + 1;
    }
    return ans;
}
int main(){
    cin >> x;
    cout << solve() << endl;
    return 0;
}