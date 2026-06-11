#include <iostream>

using namespace std;

int main()
{
    long long int W,a,b;
    cin>>W>>a>>b;
    if(b>=(a+W)) cout<<b-(a+W);
    else{
        if(a>(b+W)) cout<<a-(b+W);
        else cout<<0;
    }
    return 0;
}
