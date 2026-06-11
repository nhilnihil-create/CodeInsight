/*
*/

typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<bool> same(n);
    for (int i = 0; i < n; i++) {
        ll tmp;
        std::cin >> tmp;
        tmp--;
        if(i == tmp){
            same[i] = true;
        }else{
            same[i] = false;
        }
    }
    
    ll result = 0;
    
    for (int i = 0; i < n; i++) {
        if( same[i] ){
            same[i] = false;
            if(i<n-1){
                same[i+1] = false;
            }
            result++;
        }
    }
    std::cout << result << std::endl;
}

