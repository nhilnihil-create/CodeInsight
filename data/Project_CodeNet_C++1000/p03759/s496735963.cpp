#include <iostream>
#include <string>
using namespace std;
int m, n, i, j,a[5];

int main()
{
    for(int t=1;t<4;t++){
        cin>>a[t];
    }

    if(a[2]-a[1]==a[3]-a[2]) cout<<"YES";
    else cout<<"NO";
    return 0;
}