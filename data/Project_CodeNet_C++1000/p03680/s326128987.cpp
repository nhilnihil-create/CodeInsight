#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
  int N,cnt = 1;
  cin>>N;
  vector<int> a(N);
  
  for(int nj=0;nj<N;nj++)
  {
    cin>>a.at(nj);
  }
  int ni = 0;
  while(2 != a.at(ni))
  {
    cnt++;
    ni = a.at(ni)-1;
    if(N==cnt)
    {
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<cnt<<endl;
  return 0;
}