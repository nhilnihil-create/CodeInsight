#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  int X=0;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N ;i++)
  {
    cin >> A.at(i);
    if((A.at(i)%2) == 1)X++;
  }
  if((X%2) == 0 )cout << "YES" << endl;
  if((X%2) == 1 )cout << "NO" << endl;
}
    