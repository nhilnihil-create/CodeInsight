#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll x, y;
    cin >> x >> y;
    if(labs(x - y) >= 2)cout<<"Alice\n";
    else cout<<"Brown\n";
}