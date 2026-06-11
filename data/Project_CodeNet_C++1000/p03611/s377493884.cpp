#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL n,ans=0,freq[100100],a[100100],bil;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>bil;
        freq[bil]++;
    }
    for(int i=1;i<=100000;i++){
        ans=max(ans,freq[i]+freq[i+1]+freq[i-1]);
    }
    cout<<ans<<endl;
}
