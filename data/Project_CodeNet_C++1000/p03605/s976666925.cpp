#include <iostream>
using namespace std;

int main() {
    int n,ans=0;cin>>n;
    if(n%10==9)ans=1;
    n/=10;
    if(n%10==9)ans=1;
    if(ans==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

	return 0;
}