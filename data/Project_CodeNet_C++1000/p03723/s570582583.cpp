#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, cnt = 0;
 	cin >> a >> b >> c;
  	while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
    	int a1 = b / 2 + c / 2;
      	int b1 = a / 2 + c / 2;
      	int c1 = a / 2 + b / 2;
      	a = a1, b = b1, c = c1;
	 	cnt ++;
      	if(cnt > 1e6) break;
    }
  	if(cnt > 1e6) cout << "-1\n";
  	else cout << cnt << "\n";
}