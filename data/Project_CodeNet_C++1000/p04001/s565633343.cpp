#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
#include <cstdint>
#include <bitset>
using namespace std;
using i64 = int64_t;

int main(void){
    string s;
    cin >> s;
    i64 sum = 0;
    int n = s.size()-1;
    for(int bit=0; bit<(1<<n); bit++){
        bitset<9> bs(bit);
        int m = 0;
        for(int i=1; i<=n; i++){
            if(bs.test(i-1)){
                string t = s.substr(m, i-m);
                sum += stoll(t);
                m = i;
            }
        }
        string t = s.substr(m);
        sum += stoll(t);
    }
    cout << sum << '\n';
    return 0;
}