#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, num, even = 0, odd = 0;
    cin >> n;
    while(n--){
		cin >> num;
		if(num%2==0)even+=num;
		else odd+=num;
	}
	if((even+odd)%2==0)cout <<"YES";
	else cout <<"NO";
    return 0;
}
