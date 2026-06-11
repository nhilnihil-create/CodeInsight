




#include <bits/stdc++.h>
#include <vector>
#include <math.h>

using namespace std;







int main(){

 long long Q,diff=0;
 cin>>Q;

 while(Q--){

    long long l,r;
    cin>>l>>r;

    diff += abs(l-r)+1;
 }

  cout<<diff<<endl;

return 0;
}

