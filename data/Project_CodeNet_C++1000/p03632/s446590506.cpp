/*
      author  : nishi5451
      created : 14.08.2020 14:30:28
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(b < c || d < a) cout << 0 << endl;
    else{
        if(a < c){
            cout << min(b,d) - c << endl;
        }
        else if(c <= a){
            cout << min(b,d) - a << endl;
        }
    }
    return 0;
}