#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define print(n) std::cout << n << std::endl
#define print_no_indention(n) std::cout << n
using namespace std;


int main() {
    int a,b;
    cin >> a >> b;

    print((a + b) % 24);
}