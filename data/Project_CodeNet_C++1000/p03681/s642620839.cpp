#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m;
    cin>>n>>m;
    long long int sum=1;
    if (n==m) {
        for (long long int i=n;i>0;i--) {
            sum=(sum*i)%1000000007;
        }
        for (long long int j=m;j>0;j--) {
            sum=(sum*j)%1000000007;
        }
        cout<<(sum*2)%1000000007<<endl;
    } else if (n-m==1||m-n==1)  {
        for (long long int i=max(n,m);i>0;i--) {
            sum=(sum*i)%1000000007;
        }
        for (long long int j=min(n,m);j>0;j--) {
            sum=(sum*j)%1000000007;
        }
        cout<<sum%1000000007<<endl;
    } else {
        cout<<0<<endl;
    }
}