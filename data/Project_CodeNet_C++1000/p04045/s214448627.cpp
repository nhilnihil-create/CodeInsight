#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<queue>
#include<utility>
#include<cmath>
#include<sstream>
#include<istream>
#include<numeric>
#include<stdlib.h>

using namespace std;

int main()
{

  int N;
  int K;
  cin >> N >> K;

  vector<int> D(K);

  for(int i=0; i<K; i++){
    cin >> D[i];
  }

  while(1){
    string S = to_string(N);
    int flag = 1;

    for(int i=0; i<S.size(); i++){
      for(int j=0; j<K; j++){
        char c = '0' + D[j];
        if(S[i] == c){
          flag = 0;
          break;
        }
        if(flag == 0){
          break;
        }
      }
    }

    if(flag == 1){
      cout << N << endl;
      return 0;
    }
    N++;
  }
}
