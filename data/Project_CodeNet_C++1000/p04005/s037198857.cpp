#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
#include <set>
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    if(a%2==0||b%2==0||c%2==0)cout<<0<<endl;
    else cout<<min({a*b,a*c,b*c})<<endl;
}
