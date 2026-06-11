#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF=1001001001;


int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int e=max(a,c);
    int f=min(b,d);
    if(f-e<0) cout<<"0"<<endl;
    else cout<<f-e<<endl;
    

}
