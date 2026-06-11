#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int x = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'I') {
            x++;
        } else {
            x--;
        }

        a[i] = x;
    }

    a.push_back(0);

    std::cout << *std::max_element(a.begin(), a.end()) << "\n";
}