#include<bits/stdc++.h>

using namespace std;

const int N=1e5+7;


int main() {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(a[i]==i) {
            cnt++; i++;
        }
    }
    
    cout<<cnt<<endl;
    
    return 0;
}