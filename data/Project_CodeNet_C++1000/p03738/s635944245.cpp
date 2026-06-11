#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    std::string ans;
    if (a.size() > b.size())
    {
        ans = "GREATER";
    }
    else if (a.size() < b.size())
    {
        ans = "LESS";
    }
    else if(a.size() == b.size())
    {
        ans = "EQUAL";
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if(a[i] > b[i]) {
                ans = "GREATER";
                break;
            }
            else if (b[i] > a[i])
            {
                ans = "LESS";
                break;
            }
        }
    }

    std::cout << ans << "\n";
}
