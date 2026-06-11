#include <iostream>
using namespace std;
int main() {
    int X, A, B; cin >> X >> A >> B;
    int n = -(A - B);
    if (n <= 0) printf("%s\n", "delicious");
    else {
        if (n <= X) printf("%s\n", "safe");
        else printf("%s\n", "dangerous");
    }
}