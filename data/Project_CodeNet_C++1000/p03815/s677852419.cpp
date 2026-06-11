#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 100000;
long a[MAX_N], b[MAX_N];
long long x;
pair<long long, long long> p[MAX_N];
long solve(){
    long long count = 0 ;
    count += (x/11)*2;
    x %= 11;
    if(x != 0)  count += (x/7 + 1);  
    return count;
}
int main(){
    cin >> x;
    cout << solve() << endl;
    return 0;
}