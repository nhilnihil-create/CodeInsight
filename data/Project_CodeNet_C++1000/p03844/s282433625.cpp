#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e6+5,OO=0x3f3f3f3f;
long long A,B;
char op;
int main ()
{
    cin>>A>>op>>B;
    printf("%lld\n",op=='-'?A-B:A+B);
    return 0;
}
