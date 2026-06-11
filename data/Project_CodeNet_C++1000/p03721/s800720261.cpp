#include <bits/stdc++.h>
using namespace std;

int main(){

  int N;
  long K;
  cin >> N >>K;
  vector<pair <int,int> > array(N);

  for(int i = 0; i < N; i++){
    int a,b;
    cin >> a >> b;
    array.at(i).first = a;
    array.at(i).second = b;
  }
  
  sort(array.begin(),array.end());


  long long counter = 0;
  int answer = 0;
  for(auto num : array){
    counter += num.second;
    if (counter >= K) {
      answer = num.first;
      break;
    }
  }
  cout << answer << endl;
}
