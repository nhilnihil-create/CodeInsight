#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    int n;
    std::cin >> n;
    std::vector<ll> score(n);
    ll sum = 0;
    ll minNOT10 = 1000;
    for(int i = 0; i < n; i++){
        std::cin >> score[i];
        sum += score[i];
        if(score[i] % 10 != 0){
            minNOT10 = std::min(minNOT10, score[i]);
        }
    }

    if(minNOT10 == 1000){
        std::cout << 0 << std::endl;
    }else{
        if(sum % 10 != 0) std::cout << sum << std::endl;
        else std::cout << sum - minNOT10 << std::endl;
    }

    return 0;
}
