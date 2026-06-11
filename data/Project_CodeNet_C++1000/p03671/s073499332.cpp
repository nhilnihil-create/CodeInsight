
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()

{

  int a[3];
  for(int i=0;i<3;i++){
    cin>>a[i];
  }
  sort(a,a+3);
  for (int i = 0; i < 3; ++i){
                cout <<a[i]+a[i+1]<<endl;
                break;
  }



 return 0;
}






