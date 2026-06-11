#include<iostream>

using namespace std;

int main(void)

{
    int n, k, x, y, a;
    cin>>n>>k>>x>>y;
    if(n <= k) a = x*n;
    else a = (x*k)+((n-k)*y);
    cout<<a<<endl;
    return 0;
}