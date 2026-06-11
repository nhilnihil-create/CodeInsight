#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
  cin>>n>>k;
  int a[k];
  string ver;
  for(int i=0;i<k;i++)
  {
      cin>>a[i];
      ver+=to_string(a[i]);
  }
  string s=to_string(n);
  size_t found=s.find_first_of(ver);
  while(true)
  {
      if(found!=string::npos){
          n++;
          s=to_string(n);
          found=s.find_first_of(ver);
      }else{
        break;
      }
  }
  cout<<n<<"\n";
}
