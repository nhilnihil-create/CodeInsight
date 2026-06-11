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
  string Sa, Sb, Sc;
  cin >> Sa >> Sb >> Sc;

  queue<char> A;
  for (int i=0; i<(int)Sa.size(); i++){
    A.push(Sa.at(i));
  }

  queue<char> B;
  for (int i=0; i<(int)Sb.size(); i++){
    B.push(Sb.at(i));
  }

  queue<char> C;
  for (int i=0; i<(int)Sc.size(); i++){
    C.push(Sc.at(i));
  }

  char c = 'a';
  while (!A.empty() || !B.empty() || !C.empty()){
    if (c == 'a'){
      if (A.empty()){
        cout << 'A' << endl;
        return 0;
      }
      c = A.front();
      A.pop();
    }
    else if (c == 'b'){
      if (B.empty()){
        cout << 'B' << endl;
        return 0;
      }
      c = B.front();
      B.pop();
    }
    else {
      if (C.empty()){
        cout << 'C' << endl;
        return 0;
      }
      c = C.front();
      C.pop();
    }
  }
}
