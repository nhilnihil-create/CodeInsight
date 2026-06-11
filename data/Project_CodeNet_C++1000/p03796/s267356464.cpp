#include <bits/stdc++.h>
using namespace std;
 
int main() {
int n;
  cin>>n;
  int64_t prime = 1000000007;
int64_t after_training=1;
for(int i=1;i <=n;i++){
	after_training *= i;
  if(after_training > prime){after_training %= prime;}
}
cout<<after_training<<endl;
}