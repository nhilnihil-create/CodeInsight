#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}
 
int main() {
  int64_t N;
  cin>>N;
  
  vector<int64_t> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  
  if(N==1){
    cout<<vec.at(0)<<endl;
    return 0;
  }
  int64_t X=lcm(vec.at(0),vec.at(1));
  if(N==2) cout<<X<<endl;
  else{
    for(int i=2;i<N;i++){
      X=lcm(X,vec.at(i));
    }
    cout<<X<<endl;
  }
    
}