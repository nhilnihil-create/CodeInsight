#include<iostream>
#include<string>

using namespace std;

int main() {
	int a, b,c,ans=0;
	cin >> a>>b>>c;
	if (a != b)ans++;
	if (b != c)ans++;
	if (a != c)ans++;
  if(a==b&&b==c)ans++;
	cout << ans;
}