#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

int main(){

  int A, B, C;
  cin >> A >> B >> C;

  int modSum;
  for (int i = 1; i <= B*B; i++) {
    int Ai = A * i;
    // cout << "Ai " << Ai << endl;
    int AmodB = Ai % B;
    // cout << "AmodB " << AmodB << endl;
    modSum += AmodB;
    // cout << "modSum " << modSum << endl;
    int check = modSum % B;
    // cout << "check " << check << endl;

    if(check == C || AmodB == C){
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}