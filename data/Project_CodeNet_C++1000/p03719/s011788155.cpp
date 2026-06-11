#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A,B,C;
    cin >> A >> B >> C;
    if(C >= A && B >= C) puts("Yes");
    else puts("No");
    return 0;
}