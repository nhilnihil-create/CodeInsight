#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    int x,a,b; cin>>x>>a>>b;
    if(abs(x-a)<abs(x-b)){
        cout<<'A'<<endl;
    }
    else cout<<'B'<<endl;
}



