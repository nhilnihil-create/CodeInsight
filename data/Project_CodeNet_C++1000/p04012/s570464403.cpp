#include<iostream>
#include<string>
#include<set>
#include<algorithm>


int main() {
    std::string w;
    std::cin >> w;
    std::set<char> ws;
    
    for (int i = 0; i < w.size(); i++)
    {
        ws.insert(w[i]);
    }

    std::sort(w.begin(), w.end());
    std::string ans = "Yes";
    for (auto itr = ws.begin(); itr != ws.end(); itr++)
    {
        int num = std::upper_bound(w.begin(), w.end(), *itr) - std::lower_bound(w.begin(), w.end(), *itr);

        if(num%2) {
            ans = "No";
        }
    }

    std::cout << ans << "\n";
}