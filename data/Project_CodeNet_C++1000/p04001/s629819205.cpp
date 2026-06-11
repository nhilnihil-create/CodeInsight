#include <bits/stdc++.h>
using namespace std;

int main(){
    string data;
    cin >> data;
    int n = data.size()-1;
    __int64_t ans = 0;
    __int64_t tmp;
    for(int bit = 0; bit < (1 << n); bit++){
        tmp = data[0] - '0';
        for(int j = 0; j < n; j++){
            if(bit & (1 << j)){
                ans += tmp;
                tmp = 0;
            }
            tmp = tmp * 10 + (data[j+1] - '0');
        }
        ans += tmp;
    }
    std::cout << ans << std::endl;


}