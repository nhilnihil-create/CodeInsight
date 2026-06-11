#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int tmp=0;
    for (int i=1;i<=n;i++) {
        if (s.substr(n-i,i)==t.substr(0,i)) {
            tmp=max(tmp,i);
        }
    }
    cout<<n*2-tmp<<endl;
}