#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;

int main(){
     char a,b;
     cin >> a>>b;
     if(a=='H'&&b=='H')  cout << 'H' <<endl;
     else if(a=='H'&&b=='D') cout << 'D' <<endl;
     else if(a=='D'&&b=='H') cout << 'D' <<endl;
     else cout << 'H' << endl;
      }