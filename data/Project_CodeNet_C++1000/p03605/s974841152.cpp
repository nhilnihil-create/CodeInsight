#include <iostream>
using namespace std;
int main() {
    string N; cin >> N;
    if (N[0] == '9' || N[1] == '9') printf("%s\n", "Yes");
    else printf("%s\n", "No");
}