#include <iostream>
using namespace std;
int main() {
    int A, B, C; cin >> A >> B >> C;
    if (A <= C && C <= B) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}