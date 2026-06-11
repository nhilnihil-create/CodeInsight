/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin() , x.rend()
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ii = pair <int , int>;
void in(int &x);
// const int N = ;
#define singleCase
// #define multipleCase
stack <char> stk;
string s;
int n;

void work() {
   cin >> s;
   n = s.length();
   int sol = 0;
   for (int i = 0 ; i < n ; i++) {
      if (stk.size()) {
         int cur = stk.top();
         if (cur == 'S' && s[i] == 'T') {
            stk.pop();
            continue;
         }
      }
      stk.push(s[i]);
   }
   printf("%lu\n" , stk.size());
   return;
}

int main() {
   #ifdef multipleCase
      int nQ; in(nQ);
      while (nQ--)
         work();
   #endif
   #ifdef singleCase
      work();
   #endif
   return 0;
}

void in(int &x) {
	bool neg = false;
	register int c;
	x = 0;
	c = getchar();
	if(c == '-') {
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
	  x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
