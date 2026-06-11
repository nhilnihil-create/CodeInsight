#include <iostream>
#include <set>
using namespace std;
int main() {
    int a, b, c; cin >> a >> b >> c;
    set<int> S; 
    S.insert(a); S.insert(b); S.insert(c);
    printf("%d\n", S.size());
}