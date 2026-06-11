#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
int M;
int h, j;
cin>>N>>M;
vector<int> vec(N);
for(int i=0;i<M;i++)
{
  cin>>h>>j;
  vec.at(h-1)=1+vec.at(h-1);
  vec.at(j-1)=1+vec.at(j-1);
}
for(int i=0;i<N;i++)
{
  cout<<vec.at(i)<<endl;
}
}