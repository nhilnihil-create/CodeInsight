/*
      author : nishi5451
      created: 11.08.2020 00:21:03
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    char a,b;
    cin >> a >> b;
    if(a=='H' && b=='H'){
        cout << 'H' << endl;
    }
    else if(a=='H' && b=='D'){
        cout << 'D' << endl;
    }
    else if(a=='D' && b=='H'){
        cout << 'D' << endl;
    }
    else if(a=='D' && b=='D'){
        cout << 'H' << endl;
    }
    return 0;
}