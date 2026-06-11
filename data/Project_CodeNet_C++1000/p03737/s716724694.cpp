#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
char up(char c) {
    if ('a' <= c && c <= 'z') {
        c = c - ('a' - 'A');
    }
    return c;
}

int main (){
  string a , b , c ;
  cin >> a >> b >> c ;
  cout << up(a[0]) << up(b[0]) << up(c[0]) << endl;
}