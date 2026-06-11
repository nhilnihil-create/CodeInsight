#include <iostream>
using namespace std;
int main() {
    char a, b; cin >> a >> b;
    if ((a == 'H' && b == 'H') || (a == 'D' && b == 'D')) printf("%c\n", 'H');
    else printf("%c\n", 'D');
}