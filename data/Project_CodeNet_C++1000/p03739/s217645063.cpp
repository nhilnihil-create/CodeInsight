#include<iostream>
#include<vector>
#include<string>

// ref : https://scrapbox.io/luckyrat/%E3%80%90Comp-Prog:20190521%E3%80%91ABC059-C_Sequence

using ll = long long;

int main(){
    int n;
    std::cin >> n;
    std::vector<ll> input(n);
    for(int i = 0; i < n; i++){
        std::cin >> input[i];
    }

    // +-+-...
    long long cost1 = 0, sum1 = 0;
    std::vector<ll> a = input;
    for(int i = 0; i < n; i++){
        sum1 += a[i];
        if(i % 2 == 0 && sum1 <= 0){
            cost1 += 1 - sum1;
            a[i] += 1 - sum1;
            sum1 = 1;
        }else if(i % 2 == 1 && sum1 >= 0){
            cost1 += 1 + sum1;
            a[i] -= 1 + sum1;
            sum1 = -1;
        }
    }

    // -+-+....
    long long cost2 = 0, sum2 = 0;
    a = input;
    for(int i = 0; i < n; i++){
        sum2 += a[i];
        if(i % 2 == 0 && sum2 >= 0){
            cost2 += 1 + sum2;
            a[i] -= 1 + sum2;
            sum2 = -1;
        }else if(i % 2 == 1 && sum2 <= 0){
            cost2 += 1 - sum2;
            a[i] += 1 - sum2;
            sum2 = 1;
        }
    }

    std::cout << std::min(cost1, cost2) << std::endl;
    return 0;
}
