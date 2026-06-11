#include<bits/stdc++.h>
using namespace std;
int main()
{
int A;
int B;
cin>>A;
cin>>B;
if(A<=13 && B<=13 && A!=1 && B!=1){
  if(A>B){
    cout<<"Alice";
  }
 else if(B>A){
     cout<<"Bob";
  }
  else if(A==B){
     cout<<"Draw";
  }

}
else if(A<=13 && A!=1 && B==1){
 cout<<"Bob";

}
else if(B<=13 && B!=1 && A==1){
 cout<<"Alice";
}
else{
 cout<<"Draw";
}
return 0;
}