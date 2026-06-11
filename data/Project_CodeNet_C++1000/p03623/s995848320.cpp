 #include<bits/stdc++.h>
using namespace std;
int main(){
  int x,a,b;
  cin>>x>>a>>b;
  int c=abs(x-a);
  int d = abs(x-b);
  if(c<d)
     cout<<"A"<<endl;
  else if(c>d)
     cout<<"B"<<endl;
}