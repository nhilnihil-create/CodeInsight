#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >>d;
    int x = c-a;
    int y = d-b;
    rep(i,x)cout << "R";
    rep(i,y)cout << "U";
    rep(i,x)cout << "L";
    rep(i,y)cout << "D";
    cout << "D";
    rep(i,x+1)cout << "R";
    rep(i,y+1)cout << "U";
    cout << "L";
    cout << "U";
    rep(i,x+1)cout << "L";
    rep(i,y+1)cout << "D";
    cout << "R";
    cout << endl;
    return 0;
}