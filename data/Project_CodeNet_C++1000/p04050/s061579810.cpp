#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n, m;
  cin>>n>>m;
  int a[100];
  vector<int> odd;
  for(int i=0; i<m; i++){
    cin>>a[i];
    if(a[i]%2) odd.push_back(a[i]);
  }
  if(odd.size()>=3){
    cout<<"Impossible"<<endl;
    return 0;
  }
    
  vector<int> ap, b;
  if(odd.size()==2){
    ap.push_back(odd[0]);
    for(int i=0; i<m; i++){
      if(a[i]%2==0) ap.push_back(a[i]);
    }
    ap.push_back(odd[1]);
	if(ap[0]==1 && ap[m-1]==1){
      b.push_back(2);
      for(int i=1; i<m-1; i++){
        b.push_back(ap[i]);
      }
    }else if(ap[0]==1){
      b.push_back(2);
      for(int i=1; i<m-1; i++){
        b.push_back(ap[i]);
      }
      b.push_back(ap[m-1]-1);
    }else{
      b.push_back(ap[0]-1);
      for(int i=1; i<m-1; i++){
        b.push_back(ap[i]);
      }
      b.push_back(ap[m-1]+1);
    }
  }else if(odd.size()==1){
    if(m==1){
      ap.push_back(a[0]);
      for(int i=0; i<n/2; i++){
        b.push_back(2);
      }
      b.push_back(1);
    }else{
    ap.push_back(odd[0]);
    for(int i=0; i<m; i++){
      if(a[i]%2==0) ap.push_back(a[i]);
    }
    b.push_back(ap[0]+1);
    for(int i=1; i<m-1; i++) b.push_back(ap[i]);
    b.push_back(ap[m-1]-1);
    }
  }else{
    if(m==1){
      cout<<a[0]<<endl;
      cout<<n/2+1<<endl;
      if(n%4==2){
        cout<<1<<" ";
        for(int i=0; i<n/2/2; i++){
          cout<<2<<" ";
        }
        cout<<1<<" ";
        for(int i=0; i<n/2/2; i++){
          cout<<2<<" ";
        }
        cout<<endl;
      }else{
        cout<<1<<" ";
        for(int i=0; i<n/2/2-1; i++){
          cout<<2<<" ";
        }
        cout<<1<<" ";
        for(int i=0; i<n/2/2; i++){
          cout<<2<<" ";
        }
        cout<<endl;
      }
      return 0;
    }
    for(int i=0; i<m; i++){
      ap.push_back(a[i]);
    }
    b.push_back(ap[0]+1);
    for(int i=1; i<m-1; i++) b.push_back(ap[i]);
    b.push_back(ap[m-1]-1);
  }
  for(auto x:ap) cout<<x<<" ";
  cout<<endl;
  cout<<b.size()<<endl;
  for(auto x:b) cout<<x<<" ";
  cout<<endl;
	return 0;
}