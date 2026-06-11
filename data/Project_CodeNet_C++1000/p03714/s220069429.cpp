#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

template<typename T>
using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;

template<typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;


int main( ) {
   int n;
   std::cin >> n;

   int arr[3 * n];
   for (int i = 0; i < 3 * n; ++i) {
      std::cin >> arr[i];
   }

   min_heap<int> izq;
   long long actual_izq = 0, suma_izq[3 * n];
   for (int i = 0; i < 3 * n; ++i) {
      if (izq.size( ) == n && arr[i - 1] > izq.top( )) {
         actual_izq -= izq.top( );
         izq.pop( );
      }
      if (izq.size( ) != n && i != 0) {
         izq.push(arr[i - 1]);
         actual_izq += arr[i - 1];
      }
      suma_izq[i] = (izq.size( ) == n ? actual_izq : -1);
   }

   max_heap<int> der;
   long long actual_der = 0, suma_der[3 * n];
   for (int i = 3 * n - 1; i >= 0; --i) {
      if (der.size( ) == n && arr[i] < der.top( )) {
         actual_der -= der.top( );
         der.pop( );
      }
      if (der.size( ) != n) {
         der.push(arr[i]);
         actual_der += arr[i];
      }
      suma_der[i] = (der.size( ) == n ? actual_der : -1);
   }

   long long res = LLONG_MIN;
   for (int i = 0; i < 3 * n; ++i) {
      if (suma_izq[i] != -1 && suma_der[i] != -1) {
         res = std::max(res, suma_izq[i] - suma_der[i]);
      }
   }

   std::cout << res << "\n";
}
