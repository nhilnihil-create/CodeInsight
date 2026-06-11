#include <iostream>
using namespace std;
int main() {
    int N; cin >> N;
    int a = N / 100, b = N % 10;
    if (a == b) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}