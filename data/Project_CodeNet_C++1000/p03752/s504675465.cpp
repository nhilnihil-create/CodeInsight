#include <bits/stdc++.h>
using namespace std;

int main() {
   int N,K;
   cin >> N >> K;
   long long a[N];
   for (int i=0; i<N; i++) cin >> a[i];
   long long total=1000000000000000;
   for (int tmp=0; tmp<(1<<15); tmp++) {
       bitset<15> s(tmp);
       int k=0;
       long long count=0;
       long long b=a[0];
       for (int i=0; i<N; i++) {
           if (i==0) {
               k++;continue;
           }
           if (s[i]) {
               k++;
               if (b<a[i]) {
                   b=a[i];continue;
               }
               b++;
               count+=(b-a[i]);
           }
           b=max(b,a[i]);
       }
       if (K==k) total=min(total,count);
   }
   cout << total << endl;
}