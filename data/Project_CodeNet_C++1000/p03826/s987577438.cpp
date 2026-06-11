#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a*b > c*d) cout<<a*b<<endl;
    else if(a*b < c*d) cout<<c*d<<endl;
    else cout<<a*b<<endl;

}