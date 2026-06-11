#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,K;
  cin >> N >> K;
  vector<int>D(K);
  for (int i = 0; i < K; i++) {
    cin >> D.at(i);
  }
  
  for (int i = N; i < 10; i++) {
    int M = i;
    for (int j = 0; j < K; j++) {
      if (M % 10 == D.at(j)){
        break;
      }
      else if (j == K-1){
        M /= 10;
        if (M == 0){
          cout << i << endl;
          return 0;
        }
      }
    }
  }
  for (int i = N; i < 100; i++) {
    int M = i;
    for (int k = 0; k < 2; k++) {
    for (int j = 0; j < K; j++) {
      if (M % 10 == D.at(j)){
        break;
      }
      else if (j == K-1){
        M /= 10;
        if (M == 0){
          cout << i << endl;
          return 0;
        }
      }
    }
    }
  }
  for (int i = N; i < 1000; i++) {
    int M = i;
    for (int k = 0; k < 3; k++) {
    for (int j = 0; j < K; j++) {
      if (M % 10 == D.at(j)){
        break;
      }
      else if (j == K-1){
        M /= 10;
        if (M == 0){
          cout << i << endl;
          return 0;
        }
      }
    }
    }
  }
  for (int i = N; i < 10000; i++) {
    int M = i;
    for (int k = 0; k < 4; k++) {
    for (int j = 0; j < K; j++) {
      if (M % 10 == D.at(j)){
        break;
      }
      else if (j == K-1){
        M /= 10;
        if (M == 0){
          cout << i << endl;
          return 0;
        }
      }
    }
    }
  }
  for (int i = N; i < 100000; i++) {
    int M = i;
    for (int k = 0; k < 5; k++) {
    for (int j = 0; j < K; j++) {
      if (M % 10 == D.at(j)){
        break;
      }
      else if (j == K-1){
        M /= 10;
        if (M == 0){
          cout << i << endl;
          return 0;
        }
      }
    }
    }
  }
  cout << 100000 << endl;
}