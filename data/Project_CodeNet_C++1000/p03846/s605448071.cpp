#include <bits/stdc++.h>

using namespace std;

bool isValidVect(vector<int> &A){

  int s = A.size();
  int i0 = s % 2;

  if(i0 == 1 && A[0] != 0){
    return false;
  }

  for(int i = i0; i < s; i+=2){
    if(A[i] != i+1 || A[i+1] != i + 1){
      return false;
    }
  }

  return true;

}

int main() {
  int N;
  cin >> N;
  vector<int> A;

  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    A.push_back(a);
  }

  sort(A.begin(), A.end());
  if(!isValidVect(A)){
    cout << 0 << endl;
  } else {
    int p = A.size() / 2;
    long result = 1;
    for(int i = 0; i < p; i++){
      result *= 2;
      if(result > 1000000007){
        result %= 1000000007;
      }
    }
    cout << result << endl;
  }

  return 0;
}