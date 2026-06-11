#include <iostream>
using namespace std;
int main(){
    int x,a,b;
    cin >> x >> a >> b;
    if(b-a <= 0) puts("delicious");
    else if (b-a <= x) puts("safe");
    else puts("dangerous");
    return 0;
}