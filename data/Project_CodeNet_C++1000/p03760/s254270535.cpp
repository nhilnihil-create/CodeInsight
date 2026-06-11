#include<iostream>
#include<string>

int main() {
    std::string o, e;
    std::cin >> o >> e;

    int j = 0, k = 0;
    for (int i = 0; i < o.size() + e.size(); i++)
    {
        if(i%2 == 0) {
            std::cout << o[k];
            k++;
        }
        else
        {
            std::cout << e[j];
            j++;
        }
    }

    std::cout << "\n";
}