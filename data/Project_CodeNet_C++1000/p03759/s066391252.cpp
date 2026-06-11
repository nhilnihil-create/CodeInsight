#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(b-a == c-b) puts("YES");
    else puts("NO");
    return 0;
}