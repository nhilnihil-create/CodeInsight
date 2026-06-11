#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007

int main(){
    int a,b;
    cin >> a >> b;
    int x=a+b;
    if(x>23) cout << x-24 << endl;
    else cout << x << endl;
    return 0;
}