#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include<list>

int main() {
    int n;
    std::cin >> n;
    std::list<int> a;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }

    int flag = 0;
    for (int i = 0; i < n; i++) {
        if(flag%2==0) {
            a.push_back(v[i]);
        }
        else
        {
            a.push_front(v[i]);
        }

        flag++;
    }

    if(flag%2 == 0) {
       for (auto itr = a.begin(); itr != a.end(); itr++) {
               std::cout << *itr << " ";
       } 
    } else {
        for (auto itr = a.rbegin(); itr != a.rend(); itr++)
        {
            std::cout << *itr << " ";
        }
    }
    std::cout << "\n";
}
