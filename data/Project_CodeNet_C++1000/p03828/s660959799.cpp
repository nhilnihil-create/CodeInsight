#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
	int n;
	ll ans=1;
	cin>>n;
	vector<int> x(n+1,0);
	for (int i=2; i<=n; i++) {
        int num=i;
        for (int j=2; j<=i; j++) {
            while (num%j==0) {
                x.at(j)++;
                num/=j;
            }
        }
	}

	for (int i=2; i<=n; i++) {
        ans*=x.at(i)+1;
        ans%=MOD;
    }
	cout<<ans<<endl;
}
