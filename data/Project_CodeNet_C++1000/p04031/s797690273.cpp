#include<iostream>
#include<vector>
#include<string>

const int INF = 1000000000;

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int maxVal = -100, minVal = 100;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        maxVal = std::max(maxVal, a[i]);
        minVal = std::min(minVal, a[i]);
    }

    int minCost = INF;
    for(int i = minVal; i <= maxVal; i++){
        int tmpCost = 0;
        for(int j = 0; j < n; j++){
            tmpCost += (i - a[j]) * (i - a[j]);
        }

        minCost = std::min(minCost, tmpCost);
    }

    std::cout << minCost << std::endl;
    return 0;
}
