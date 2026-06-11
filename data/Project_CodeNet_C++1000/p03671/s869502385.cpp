#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int max=a;
    if(b>=a&&b>=c){
        max=b;
    }   
    if(c>=b&&c>=a){
        max=c;
    }
    cout<<a+b+c-max<<endl;
    return 0;
}
