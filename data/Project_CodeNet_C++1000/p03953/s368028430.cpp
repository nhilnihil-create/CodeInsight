#include<bits/stdc++.h>
using namespace std;

vector<int> res;
void perm_mult(vector<int> &P1, vector<int> &P2)
{
  int i;
  std::vector<int> v;
  for(i=0;i<P1.size(); i++)
  {
    v.push_back(P1[P2[i]]);
  }
  for(i=0;i<P1.size(); i++)
  {
    P1[i] = v[i];
  }
}
void Permuation_exponentiation(vector<int> &P, int n, long long K)
{
  int i;
  for(i=0;i<n;i++)
    res.emplace_back(i);

  while(K!=0)
  {
    if(K&1)
    {
      perm_mult(res, P);
    }
    perm_mult(P, P);
    K = K >> 1;
  }
}
int main()
{
  int N;
  cin >> N;
  map<int, int> mp;
  std::vector<int> v;
  int i,j, x[100000], a[100000];

  for(i=0;i<N;i++)
    cin >> x[i];

  long long M, K;
  cin >> M>>K;

  for(i=0;i<M;i++)
  {
    cin >> a[i];
    a[i]-=2;
  }

  int k = 0;
  for(i=1;i<N;i++)
  {
    v.push_back(i-1);
    mp[k++]=x[i]-x[i-1];
  //  cout<<v[k-1]<<" "<<k<<endl;
  }
//cout<<endl;
  for(i=0;i<M;i++){
    //cout<<i<< " "<<v[a[i]]<<v[a[i]+1]<<endl;
    swap(v[a[i]], v[a[i]+1]);
  }

  Permuation_exponentiation(v, v.size(), K);
  cout<<x[0]<<endl;
  long long prev = x[0];
  for(i=1;i<N-1;i++)
  {
    int d = mp[res[i-1]];
    cout<< prev+d<<endl;
    prev = prev+d;
  }
  cout<<x[N-1]<<endl;
}
