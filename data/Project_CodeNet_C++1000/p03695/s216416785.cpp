#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::set<int> as;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int vari = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] >= 3200) {
            vari++;
        } else if(a[i] >= 2800) {
            as.insert(0);
        } else if(a[i] >= 2400) {
            as.insert(1);
        } else if(a[i] >= 2000) {
            as.insert(2);
        } else if(a[i] >= 1600) {
            as.insert(3);
        } else if(a[i] >= 1200) {
            as.insert(4);
        } else if(a[i] >= 800) {
            as.insert(5);
        } else if(a[i] >= 400) {
            as.insert(6);
        } else{
            as.insert(7);
        }
    }

    int minans = as.size();
    if (as.size() == 0)
    {
        minans = 1;
    }
    std::cout << minans << " " << as.size() + vari << "\n";
}