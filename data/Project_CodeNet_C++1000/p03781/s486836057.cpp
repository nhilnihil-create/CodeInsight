#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    ll x,su=0;cin>>x;
    for(int i=1;i<=100000;i++){
        su+=i;
        if(su>=x){
            cout<<i<<endl;
            return 0;
        }
    }
}
