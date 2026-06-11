#include <bits/stdc++.h>
using namespace std;

int main() {
  int Ntot, Nsort;
  cin >> Ntot >> Nsort;

  vector<int> data(Nsort);
  for(int i=0; i<Nsort; i++){
    cin >> data.at(i);
  }
  sort(data.begin(), data.end(), greater<int>());

  int Nminor= Ntot- data.at(0);
  int ans= max(0, data.at(0)- 1- Nminor);

  cout << ans << endl;
}