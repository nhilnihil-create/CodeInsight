#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    int x,a,b;
    cin>>x>>a>>b;

    cout<< ( (abs(a-x)<abs(b-x) ? 'A' : 'B')) <<endl;


    return 0;
}
