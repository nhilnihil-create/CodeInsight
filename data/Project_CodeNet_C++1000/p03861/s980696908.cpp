#include <bits/stdc++.h>
using namespace std ;
int main()
{
    while(1) // for test
    {
    unsigned long long a , b , x , cnt = 0;
    cin >>  a >> b >> x ;
    cnt = (b / x) - (a / x) ;
    if(!(a % x)) cnt++ ;
    cout << cnt <<endl ;
    break ;
    }

}
