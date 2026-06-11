#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n , a[N] , b[N];
map < int , bool > mp; 
main(){
	scanf("%d" , &n);
    for(int i = 1 ; i <= n; i++)
      	scanf("%d" , a + i) , b[i] = a[i];
	sort(b + 1, b + 1 + n);
  	for(int i = 1 ;  i <= n ; i++)
      	mp[b[i]] = i&1;
  	int pos = 1 , ans = 0;
  	for(int i = 1 ; i <= n ; i++)
      	if(mp[a[i]])
          	ans += abs(pos - i) % 2 , pos += 2;
 	cout << ans;
}