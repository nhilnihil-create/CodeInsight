#include <iostream>
using namespace std;

int main() {
    int n;cin>>n;
    const int INF = 1000000007;
    long long ans=1;
    for(int i=1;i<=n;++i){
        ans*=i;
        ans%=INF;
    }
    cout<<ans<<endl;
	return 0;
}