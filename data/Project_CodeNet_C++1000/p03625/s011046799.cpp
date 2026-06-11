#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL n,ans=0,a[100100],p,l,idx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        if(a[i]==a[i-1]){
            p=a[i];
            idx=i;
            break;
        }
    }
    for(int i=idx-2;i>=1;i--){
        if(a[i]==a[i-1]){
            l=a[i];
            break;
        }
    }
    cout<<p*l<<endl;
}
