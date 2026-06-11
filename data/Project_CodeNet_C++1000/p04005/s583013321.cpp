#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> vec(3);
    for(int i = 0; i < 3; i++) {
        cin >> vec.at(i);
    }
    sort(vec.begin(),vec.end());
    
    long long a = vec.at(0);
    long long b = vec.at(1);
    long long c = vec.at(2);
    
    long long result;
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
        result = 0;
    } else {
        result = (a * b);
    }
    
    cout << result << endl;
}
