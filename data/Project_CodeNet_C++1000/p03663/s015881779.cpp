#include <bits/stdc++.h>


using namespace std;

map <long long, char> mp;

inline char check(long long x) {
     cout << "?" << " " << x << endl;
    // fflush(stdout);
     char ch;
     cin >> ch;
     return ch;
}

int main() {
  //  fstream cin("B.in");
  //  ofstream cout("B.out");
    int rez, pas, i;
    ios::sync_with_stdio(false);
    long long x;
    if(check(1e9) == 'Y') {
        x = 2;
        while(check(x) == 'N')
            x *= 10;
        cout << "!" << " " << x / 2 << endl;
        return 0;
    }
    x = 1;
    int sz = 1;
    while(check(x) == 'Y') {
        x = x * 10;
        sz++;
    }
    sz--;
    x = 0;
    for(i = 1; i < sz; i++) {
        rez = 0;
        for(pas = 1 << 3; pas; pas >>= 1)
          if(rez + pas < 10)
              if(check(x * 10 + rez + pas) == 'Y')
                 rez += pas;
        x = x * 10 + rez;
    }
    rez = -1;
    for(pas = 1 << 3; pas; pas >>= 1)
       if(rez + pas < 10 && check(x * 100 + (rez + pas) * 10) == 'N')
           rez += pas;
    cout << "!" << " " << x * 10 + (rez + 1) << endl;
  //  cin.close();
  //  cout.close();
    return 0;
}
