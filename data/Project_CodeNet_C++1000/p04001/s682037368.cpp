#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long sum = 0;
    int length = s.length();
    long long number = stol(s);

    for(int i = 0; i < pow(2, length - 1); ++i){
        int bits = i;
        long long p = number;
        // cout << bitset<10>(bits) << " ";
        for(int j = 0, q = 1; j < length - 1; ++j){            
            q = q * 10;
            if((bits >> j) & 1){
                sum += p % q;
                // cout << p % q << " ";
                p = p / q;
                q = 1;
            }
        }
        sum += p;
        // cout << sum << endl;
    }
    cout << sum << endl;
}