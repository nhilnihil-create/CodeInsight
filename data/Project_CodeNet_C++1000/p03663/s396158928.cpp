#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
void f(ll n ){
  char c;
  cout<< "? "<<n*2<<endl;
  cin>>c;
  if(c=='Y'){
    cout<<"! "<<n<<endl;
  }else{
    f(n*10);
  }
  return;
}

void h(ll n,ll m){
  ll a = (n+m)/2;
  if( m-n==2){
    cout <<"! "<<a<<endl;
    return;
  }
  
  char c;
  cout<<"? "<<a*10<<endl;
  cin>>c;
  if(c=='Y'){
    h(n,a+1);
  }else{
    h(a,m);
  }
  return;
}
    
    


void g(ll n ){
  char c;
  cout<< "? "<<n<<endl;
  cin>>c;
  if(c=='Y'){
    h(n,n*10);
  }else{
    g(n/10);
  }
  return;
}
  


int main() {
  char c;
  cout << "? 1000000000"<<endl;
  cin>>c;
  if( c=='Y'){
    f(1);
  }else{
    g(100000000);
  }
  

  return 0;
}
