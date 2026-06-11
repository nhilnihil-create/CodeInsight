#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
  string S;
  cin >> S;

  string T;
  cin >> T;

  int q;
  cin >> q;
  
  int score1=0;
  vector<int> count1;
  count1.push_back(score1);
  for ( int I=0 ; I<S.length(); ++I ) {
    score1 += (S[I]=='A')? 1 : 2;
    count1.push_back(score1);
  }

  int score2=0;
  vector<int> count2;
  count2.push_back(score2);
  for ( int I=0 ; I<T.length(); ++I ) {
    score2 += (T[I]=='A')? 1 : 2;
    count2.push_back(score2);
  }

  for ( int I=0 ; I<q; ++I ) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int s1 = count1[a-1];
    int e1 = count1[b];
    int s2 = count2[c-1];
    int e2 = count2[d];
    int score1 = e1 - s1; 
    int score2 = e2 - s2;
    cout<< ( ( score1 % 3 == score2 % 3 )? "YES" : "NO") << endl; 
  }


} 