#include <iostream>

using namespace std;

int main()
{
    int n,l,r,i,sum=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>l>>r;
        sum+=(r-l+1);
    }
    cout<<sum;
    return 0;
}
