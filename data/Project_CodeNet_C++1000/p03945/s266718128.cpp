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

  string S;
  cin >> S;

  long long int cnt = 0;

  for(int i=0; i<S.length()-1; i++){
    if(S[i] != S[i+1]){
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
