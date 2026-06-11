#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    int x,a,b;
    cin>>x>>a>>b;
    if(abs(a-x)>abs(b-x))cout<<'B'<<endl;
    else cout<<'A'<<endl;
}