#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

int main () {
    int n;
    std::cin >> n;

    int ans = 1;
    int num;
    while (ans <= n)
    {
        num = ans;
        ans *= 2;
    }


    std::cout << num << "\n";
}