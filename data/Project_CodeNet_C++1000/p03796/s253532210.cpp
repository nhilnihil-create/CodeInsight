#include <bits/stdc++.h>
using namespace std;

int main(){
long long a=1000000000+7;
int n;
  cin >> n;
  long long s;
  long long t=1;
for(int i=1;i<=n;i++){
t*=i;
s=t%a;
t=s;  
} 
cout << t << endl;
}