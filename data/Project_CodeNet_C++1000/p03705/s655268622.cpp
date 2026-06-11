#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a,b;
    cin>>n>>a>>b;
    if (a>b) {
        cout<<0<<endl;
    } else {
        if (n>1) {
            long long int min=a+b+a*(n-2);
            long long int max=a+b+b*(n-2);
            cout<<max-min+1<<endl;
        } else {
            if (a==b) {
                cout<<1<<endl;
            } else {
                cout<<0<<endl;
            }
        }
    }
}