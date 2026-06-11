#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll findSum(ll a[], int N, ll size) {
      ll sum = 0;

      for(ll i=size-2; i>=size-(N*2); i-=2) {      // size - 2 - 2*(N-1) = size - 2 - 2N + 2 = size - 2N
            sum += a[i];
      }
      return sum;
}

int main() {
      int N;
      cin >> N;
      ll size = 3*N;
      ll a[size];
      for(ll i=0; i<size; i++) {
            cin >> a[i];
      }
      sort(a, a+size);

      cout << findSum(a, N, size) << endl;
}