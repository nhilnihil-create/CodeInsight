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
        string t = {s[0]};
        for(int i=1; i<=n; i++){
            if(bs.test(i-1)){
                sum += stoll(t);
                t = s[i];
            }
            else t += s[i];
        }
        sum += stoll(t);
    }
    cout << sum << '\n';
    return 0;
}