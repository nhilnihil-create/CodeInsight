#include <bits/stdc++.h>
#include <vector>
#include <string.h>

typedef long long ll;
typedef long double lg;

using namespace std;

int main(){

 long long n,a,b;
 cin>>n>>a>>b;

  long long result =0 ;

  if(n == 1){
    if(a == b)
        result = 1;
    else
        result = 0;
  }
 else {
    if(a>b)
        result = 0;
    else
        result = (b-a)*(n-2)+1;
// may anyone explain why are we talking the value as this
 }

 cout<<result<<endl;

return 0;
}
