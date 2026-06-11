#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define r_rep(i, n) for(int i = n; i >= 0; i--)
#define ll long long int
#define pb push_back

const long long INF = 1LL << 60;

int main() {
  string A, B, C;
  int a =0, b=0, c=0;
  int point = 0;
  cin >> A >> B >> C;

  while(1){
    if(a==A.size() && point==0) {
      print("A");
      return 0;
    } else if (b==B.size() && point == 1) {
      print("B");
      return 0;
    } else if (c==C.size() && point == 2){
      print("C");
      return 0;
    }
    if (point == 0){
      if(A[a] == 'b') point = 1;
      if(A[a] == 'c') point = 2; 
      a++;
    } else if (point == 1){
      if(B[b] == 'a') point = 0;
      if(B[b] == 'c') point = 2; 
      b++;
    } else {
      if(C[c] == 'a') point = 0;
      if(C[c] == 'b') point = 1;
      c++;
    }
  }

}
