#include<bits/stdc++.h>
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;

typedef long long LL;

int main(){
    ios::sync_with_stdio(false);
    LL X,Y;
    cin>>X>>Y;
    if(abs(X-Y)<=1) cout<<"Brown"<<endl;
    else cout<<"Alice"<<endl;
    return 0;
}
