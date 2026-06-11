#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;

int main(){
     int w,a,b;
     cin >>w>>a>>b;
     if(a>b) swap(a,b);

     if (a+w>=b) {cout <<0 <<endl;
     return 0;}
     cout << b-a-w << endl;
      }