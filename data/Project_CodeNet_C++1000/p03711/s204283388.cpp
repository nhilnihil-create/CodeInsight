#include <iostream>
using namespace std;
int main() {
    int x, y; cin >> x >> y;
    if ((x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12) && (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)) printf("%s\n", "Yes");
    else if ((x == 4 || x == 6 || x == 9 || x == 11) && (y == 4 || y == 6 || y == 9 || y == 11)) printf("%s\n", "Yes");
    else if (x == 2 && y == 2) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}