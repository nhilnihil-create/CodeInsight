#include <iostream>

using namespace std;
int main()
{
    int N;
    cin>>N;
    int lastDigit = N%10, firtDigit=(N/100);
    if(firtDigit==lastDigit) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}