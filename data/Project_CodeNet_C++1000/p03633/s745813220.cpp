#include <bits/stdc++.h>
using namespace std;

long long f (long long x, long long y) {
   long long a=min(x,y);
   long long i,xx=x,yy=y,b;
   for (i=1; i<=sqrt(a); i++) {
      if (x%i==0 && y%i==0 && i!=1) {
         xx=x/i,yy=y/i;break;
      }
      if (a%i==0) {
         b=a/i;
         if (x%b==0 && y%b==0) {
            xx=x/b;
            yy=y/b;
            i=b;
            break;
         }
      }
   }
   if (x==xx) return 1;
   else return i*f(xx,yy);
}

int main() {
   int N;
   cin >> N;
   long long T[N];
   long long t;
   for (int i=0; i<N; i++) {
      cin >> T[i];
      if (i==0) t=T[i];
      else {
         t=t/f(t,T[i])*T[i];
      }
   }
   cout << t << endl;
}