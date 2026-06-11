#include <bits/stdc++.h>
using namespace std;

string S;
void search(long ret, long pooled, int position, long &count){
  if (position == (S.size() - 1)){
    //cout << ret + pooled * 10 + S[position] - '0' << endl;
    count += ret + pooled * 10 + S[position] - '0';
    //cout << ret + pooled + S[position] - '0' << endl;;
    count += ret + pooled + S[position] - '0';
    return;
  }
  search(ret+pooled, S[position]-'0', position+1, count);
  search(ret, pooled * 10 + S[position] - '0', position+1, count);
  return;
}


int main(){
  cin >> S;
  int val = 0;
  long count = 0;
  search(0, 0, 0, count);
  cout << count / 2 << endl;
}
