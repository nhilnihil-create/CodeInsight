#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n,k;cin>>n>>k;
    int d[k];
    rep(i,k)cin>>d[i];
    
    while(true){
    int tmp = n;
    int tmp2 = 0;
    while(tmp>0){
    rep(i,k){
        if(tmp%10==d[i]){
            tmp2=1;
            break;
        }
    }
    tmp/=10;
    }
    if(tmp2==0){
        cout<<n<<endl;
        return 0;
    }
    else ++n;
    }
	return 0;
}