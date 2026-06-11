#include <bits/stdc++.h>
using namespace std;

int main() {
  int number_of_student, number_of_checkpoint;
  cin >> number_of_student >> number_of_checkpoint;

  const int NMMAX = 50;
  int A[NMMAX], B[NMMAX], C[NMMAX], D[NMMAX];

  for(int i=0; i < number_of_student; i++) {
    cin >> A[i] >> B[i];
  }
  for(int i=0; i < number_of_checkpoint; i++) {
    cin >> C[i] >> D[i];
  }

  for(int i=0;i<number_of_student; i++) {
    int min_dist = abs(A[i]-C[0])+abs(B[i]-D[0]), checkpoint=1;

    for(int j=1; j<number_of_checkpoint; j++) {
      const int cur_dist = abs(A[i]-C[j])+abs(B[i]-D[j]);
      if(min_dist > cur_dist) {
        min_dist = cur_dist;
        checkpoint = j+1;
      }
    }
    cout << checkpoint << endl;
  }
}