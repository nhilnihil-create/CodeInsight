#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    unsigned long long n,m;
    cin>>n>>m;
    if (n>=(m/2)){
        cout<<m/2;
    }else{
        cout<<n+(m-2*n)/4<<endl;
    }
    return 0;
}