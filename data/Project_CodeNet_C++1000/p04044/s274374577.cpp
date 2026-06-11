#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<string>word(n);
  for(int i=0;i<n;i++)
    cin >> word.at(i);
  sort(word.begin(),word.end());
  for(int i=0;i<n;i++)
    cout << word.at(i);
  cout << endl;
}