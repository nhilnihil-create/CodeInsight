#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int gcd(int a,int b){
if(b==0) return a;
return gcd(b, a%b);
}

int main()
{
    ll x,y;
    cin >>x >>y;
    if(abs(x-y)>1) cout << "Alice" <<endl;
    else cout << "Brown" <<endl;
    return 0;
}