#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string a,b;cin>>a>>b;
    int a1,b1;
    if(a[0]=='H')a1=1;
    else a1=-1;

    if(b[0]=='H')b1=1;
    else b1=-1;    
    
    if(a1*b1==1)cout<<'H'<<endl;
    else cout<<'D'<<endl;

	return 0;
}