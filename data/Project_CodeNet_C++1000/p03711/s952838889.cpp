#include <iostream>
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    int a[] = {0,1,3,1,2,1,2,1,1,2,1,2,1,};
    if(a[x] == a[y]) puts("Yes");
    else puts("No");
    return 0;
}