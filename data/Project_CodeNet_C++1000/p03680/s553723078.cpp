#include <iostream>
using namespace std;
 
   int main()
   {
       int N;
       cin >> N;
       int a[N];
       bool visited[N];
       for (int i=0; i<N; i++) {
           cin >> a[i];
       }
       for (int i=0; i<N; i++) {
           visited[i] = false;
       }
       visited[0] = true;
       int next = a[0];
       if (next == 2) {
           cout << 1 << endl;
           return 0;
       }
       int cnt = 1;
       for (int i=0; i<N-1; i++) {
           if (!visited[next-1]) {
               next = a[next-1];
               cnt += 1;
               if (next == 2) {
                   cout << cnt << endl;
                   return 0;
               }
           }
       }
       cout << -1 << endl;
    }