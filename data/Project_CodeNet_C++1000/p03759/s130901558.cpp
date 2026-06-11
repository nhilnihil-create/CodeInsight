#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 5005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int main() {
  int a, b, c;
  cin>>a>>b>>c;
  if (b-a==c-b) {
  	cout<<"YES"<<endl;
  } else {
  	cout<<"NO"<<endl;
  }
	return 0;
}