/*
      author : nishi5451
      created: 11.08.2020 00:53:55
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    if(a%3==0 || b%3==0 || (a+b)%3==0)
        cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}