#include <bits/stdc++.h>
using namespace std;

int n,a[100005];

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++) {
        if(i+1>a[i+1]) {
            int j=0;
            while(a[j+i+1]==i)++j;
            if((a[i]-i)%2 || j%2) cout<<"First";
            else cout<<"Second";
            return 0;
        }
    }
}