#include <iostream>
#define ll long long
using namespace std;

int main() {
      int N;
      cin >> N;
      ll A[N];

      for(int i=0; i<N; i++) {
            cin >> A[i];
      }

      int count = 1;        // given N>=1, there will at least be 1 subarray
      int order = 0;        // 0 - reset (partition);     1 - ascending;       2 - descending

      for(int i=1; i<N; i++) {
            if((order == 1 && A[i]<A[i-1]) || (order == 2 && A[i]>A[i-1])) {  // set partition
                  order = 0;
                  count++;
            }     
            else if(A[i] > A[i-1]) order = 1;
            else if(A[i] < A[i-1]) order = 2;
      }
      
      cout << count << endl;
}