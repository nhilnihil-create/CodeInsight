/*
      author : nishi5451
      created: 11.08.2020 00:11:42
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int rect1 = a*b;
    int rect2 = c*d;
    if(rect1 >= rect2) cout << rect1 << endl;
    else cout << rect2 << endl;
    return 0;
}