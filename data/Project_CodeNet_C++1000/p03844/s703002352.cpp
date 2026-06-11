#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  char op;
  cin >> a>>op>>b;
  int sum=a;
  //char c=s2.at(0);
	if(op=='+'){
      sum+=b;
      cout<<sum<<endl;
    }
  else{
    sum-=b;
    cout<<sum<<endl;
  }
  //cout<<s1[0]<<s2[0]<<s3[0]<<endl;

}

