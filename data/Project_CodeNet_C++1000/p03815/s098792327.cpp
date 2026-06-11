#include <iostream>
using namespace std;

int main(void){
    long long x,ans;
    cin>>x;

    ans = x / 11 * 2;
    if(x%11 >6) ans += 2;
    else if(x%11 >0) ans ++;
    cout<<ans<<endl;

}