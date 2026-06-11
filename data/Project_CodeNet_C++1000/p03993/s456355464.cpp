#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int ans=0;
  int B;
  int C;
  int E,F;
  vector<int> A(N);
  for(int i=0; i<N ; i++)
  {
    cin >> A.at(i);
  }
  for(int j=0; j<N ; j++)
  {
  
      C=A.at(j);
      C--;
      B=A.at(C);
      B--;

      if(B==j)
      {
        ans++;
      }
    
  }
  cout << (ans/2) << endl;
}
