#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<string> vec_str(M * 2);
  vector<int> vec_int(N);
  for(int i = 0; i < M * 2; i++) cin >> vec_str.at(i);
  for(int i = 0; i < vec_str.size(); i++) vec_int.at(atoi(vec_str.at(i).c_str()) - 1) += 1;
  for(int i = 0; i < vec_int.size(); i++) cout << vec_int.at(i) << endl;
}