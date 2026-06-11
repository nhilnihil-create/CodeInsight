#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >>  s[i];
        sum += s[i];
    }

    std::sort(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        if(sum%10 == 0 && sum != 0){
            if(s[i]%10 == 0) {
                continue;
            }

            sum -= s[i];
        } else {
            break;
        }
    }

    bool f = false;
    for (int i = 0; i < n; i++) {
        if(s[i]%10) {
            f = true;
            break;
        }
    }

    if(!f) {
        sum = 0;
    }

        std::cout << sum << "\n";
}