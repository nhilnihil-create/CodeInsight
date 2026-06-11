#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

ll fnc(ll a, ll b, ll c){
    if(a%2 !=0 || b%2 !=0 || c%2 !=0){
        return 0;
    }
    if(a==b && b==c && a==c){
        return -1;
    }
    return fnc((b+c)/2, (a+c)/2, (b+a)/2)+1;
}


int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    cout << fnc(a, b, c) << endl;
    return 0;
}
