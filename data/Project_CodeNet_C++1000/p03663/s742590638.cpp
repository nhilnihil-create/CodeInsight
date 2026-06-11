#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>
#include <fstream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;

#define INF 1000000007ll
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )
#define SIZE 0

bool ask (ll n) {
   printf("? %lld\n", n);
   fflush(stdout);
   char res;
   cin >> res;
   return (res == 'Y');
}

int main() {
   ll n = 1, dig = 0;
   for (int i = 1 ; i <= 10 ; ++i) {
      bool res = ask(n);
      if (!res) {
         dig = i - 1;
         break;
      }
      n *= 10ll;
   }
   if (dig == 0) {
      n = 9; dig = 1;
      for (int i = 1 ; i <= 10 ; ++i) {
         bool res = ask(n);
         if (res) {
            printf("! %lld\n", dig);
            fflush(stdout);
            return 0;
         }
         n *= 10ll;
         dig *= 10;
         n += 9;
      }
      printf("! 1\n");
      fflush(stdout);
      return 0;
   }
   ll pw = pow(10, dig), num = 0;
   for (int i = dig ; i > 0 ; --i) {
      ll e = 10, s = 0;
      if (i == 1) e = 9;
      while (e - s > 1) {
         ll m = (e + s) / 2;
         ll mm = num + m * pw;
         if (ask(mm)) e = m;
         else s = m;
      } 
      if (i != 1) num += s * pow(10, i);
      else num += e * pow(10, i);
      pw /= 10;
   }
   cout << "! " << num / 10 << endl;
   return 0;
}