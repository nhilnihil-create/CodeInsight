#include <iostream>
#include <string>
using namespace std;
int main(){
    int n; cin >> n;
    bool flag = false;
    if(n%10 == 9) flag = true;
    if(n/10 == 9) flag = true;
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}