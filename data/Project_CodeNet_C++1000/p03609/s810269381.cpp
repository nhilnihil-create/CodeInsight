#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main () {
    int X,t;

    cin >>X>>t;

    if (X < t) cout << '0' << endl;
    else cout << X-t <<endl;


}
