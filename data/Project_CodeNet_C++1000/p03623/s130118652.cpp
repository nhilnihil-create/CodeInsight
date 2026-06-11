#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
using namespace std;


void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,a,b,w,q;
    cin >> x>>a>>b;
    w=abs(x-a);
    q=abs(x-b);
    if (w<q) cout<<"A";
    else cout << "B";
    


    return 0;
}