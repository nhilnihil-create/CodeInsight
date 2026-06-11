#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
#include<bitset>
#include<queue>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  string S;
  cin >> S;

  int cnt=0;
  for (int i=0; i<(int)S.size()-1; i++){
    if (S.at(i)!=S.at(i+1)){
      cnt++;
    }
  }
  cout << cnt << endl;
}
