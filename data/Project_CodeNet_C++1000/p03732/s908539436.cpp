#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, Weight, W1234, Val;
  scanf("%lld %lld", &N, &Weight);
  vector<long long> v(N),w(N);
  vector<vector <long long>> Value(4);
  long long ans = 0;


  scanf("%lld %lld", &w.at(0), &v.at(0));
  Value.at(0).push_back(v.at(0));

  for ( int i = 1; i < N; i++ ){
    scanf("%lld %lld", &w.at(i), &v.at(i));
    if ( w.at(i) == w.at(0) ) Value.at(0).push_back(v.at(i));
    else if ( w.at(i) == w.at(0) + 1 ) Value.at(1).push_back(v.at(i));
    else if ( w.at(i) == w.at(0) + 2 ) Value.at(2).push_back(v.at(i));
    else Value.at(3).push_back(v.at(i));
  }
  for ( int i = 0; i < 4; i++)
    sort(Value.at(i).begin(),Value.at(i).end(), greater<long long>());
/*
  for ( int j = 0; j < 4; j++ ){
    for ( int i = 0; i < Value.at(j).size(); i++ ){
      cout << Value.at(j).at(i) << " ";
    }
    cout << endl;
  } */
  
  for (int w0 = 0; w0 <= Value.at(0).size(); w0++ ){
    for (int w1 = 0; w1 <= Value.at(1).size(); w1++ ){
      for (int w2 = 0; w2 <= Value.at(2).size(); w2++ ){
        for (int w3 = 0; w3 <= Value.at(3).size(); w3++ ){
          W1234 = (w0 + w1 + w2 + w3) * w.at(0) + w1 + 2 * w2 + 3 * w3;
          if ( Weight >= W1234 ){
            Val = 0LL;
            for (int a = 0; a < w0; a++ ) Val += Value.at(0).at(a);
            for (int b = 0; b < w1; b++ ) Val += Value.at(1).at(b);
            for (int c = 0; c < w2; c++ ) Val += Value.at(2).at(c);
            for (int d = 0; d < w3; d++ ) Val += Value.at(3).at(d);
            ans = max(ans, Val);
          }
        }
      }
    }
  }


  printf("%lld\n", ans);
}