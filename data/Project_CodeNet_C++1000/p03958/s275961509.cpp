#include<bits/stdc++.h>
using namespace std;
int main() {
    int k,t,a[100],maxx=INT_MIN;
    cin>>k>>t;
    for(int i=0; i<t; ++i) {
        cin>>a[i];
        if(a[i]>maxx) {
            maxx=a[i];
        }
    }
    cout<<max(maxx*2-1-k,0);
    return 0;
}
