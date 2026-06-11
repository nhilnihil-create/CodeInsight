#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int a,b;
    cin >> a >> b;
    int ans = (a + b) % 24;
    cout << ans << endl;
}
