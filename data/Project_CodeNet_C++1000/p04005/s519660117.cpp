#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int a,b,c;
    cin>>a>>b>>c;
    if (a>=b&&a>=c) {
        if (a%2==0) {
            cout<<abs((a/2)*b*c-(a/2)*b*c)<<endl;
        } else {
            cout<<abs((a/2)*b*c-(a/2+1)*b*c)<<endl;
        }
    } else if (b>=a&&b>=c) {
        if (b%2==0) {
            cout<<abs((b/2)*a*c-(b/2)*a*c)<<endl;
        } else {
            cout<<abs((b/2)*a*c-(b/2+1)*a*c)<<endl;
        }
    } else {
        if (c%2==0) {
            cout<<abs((c/2)*b*a-(c/2)*b*a)<<endl;
        } else {
            cout<<abs((c/2)*b*a-(c/2+1)*b*a)<<endl;
        }
    }
}