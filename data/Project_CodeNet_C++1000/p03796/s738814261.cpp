#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    long long s=1;
    cin>>x;
    for(int i=2;i<=x;i++){
        s*=i;
        s%=1000000000+7;
    }
    cout<<s;
       return 0;
}
