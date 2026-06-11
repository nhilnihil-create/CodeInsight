#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    ll n, t;
    std::cin >> n >> t;
    ll last = 0; // お湯が切れたタイミング
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll tmp;
        std::cin >> tmp;
        if(last <= tmp){
            sum += t;
            last = tmp + t;
        }else{
            if(tmp + t > last){
                sum += tmp + t - last;
                last = tmp + t;
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
