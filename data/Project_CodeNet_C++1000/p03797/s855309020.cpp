// Danielxlr
// https://atcoder.jp/contests/abc055/tasks/arc069_a
// math
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long n,m;
    cin>>n>>m;

    if(m<2*n){
        cout<<min(n,m/2);
    }
    else{
        cout<<(2*n+m)/4;
    }
    return 0;
}