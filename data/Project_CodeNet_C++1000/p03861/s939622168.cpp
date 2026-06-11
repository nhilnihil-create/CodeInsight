#include <iostream>
#include <string>
 
int main()
{
    using namespace std;
    
    long int a, b, x;
    cin >> a >> b >> x;
 
    long int cnt = b/x;
    if(a==0)
        cnt += 1;
    else
        cnt -= (a-1)/x;
    cout << cnt << endl;
    return 0;
}