#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    cout<< ((a*b > c*d) ? a*b : c*d ) <<endl;

    return 0;
}