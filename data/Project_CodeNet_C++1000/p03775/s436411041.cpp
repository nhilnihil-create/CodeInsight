#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long f(long long a, long long b){
    string s1, s2;
    s1 = to_string(a);
    s2 = to_string(b);

    return max(s1.size(), s2.size());
}

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> ret;
    ret = divisor(n);

    long long minv = 1e12;
    for(long long i = 0; i < ret.size(); i++){
        minv = min(minv, f(ret[i], n/ret[i]));
    }
    cout << minv << endl;
    return 0;
}