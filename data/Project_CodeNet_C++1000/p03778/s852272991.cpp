/*
      author  : nishi5451
      created : 12.08.2020 23:12:10
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int w,a,b;
    cin >> w >> a >> b;
    int la = a, ra = a+w;
    int lb = b, rb = b+w;

    if( (la>=lb && la<=rb) || (ra>=lb && ra<=rb) || (la<=lb && ra>=rb) ){
        cout << 0 << endl;
    }
    else{
        if(a>b) cout << a-b-w << endl;
        else if(b>a) cout << b-a-w << endl;
    }

    return 0;
}