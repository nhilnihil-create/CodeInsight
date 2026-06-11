#include <bits/stdc++.h>
using namespace std;

// 1番短い串とペアを組むべきなのはその次に短い串。つまり貪欲法でOK
int main(){
  int N;
  cin >> N;
  int Nskew= 2*N;

  vector<int> data(Nskew);
  for(int i=0; i<Nskew; i++){
    cin >> data.at(i);
  }
  sort(data.begin(), data.end());

  int ans= 0;
  for(int i=0; i<Nskew; i+=2){
    ans+= data.at(i);
  }

  cout << ans << endl;
}