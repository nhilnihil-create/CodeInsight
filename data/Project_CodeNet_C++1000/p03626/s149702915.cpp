#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <cstdio>
#include <cstring>
#include <numeric>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)

int main()
{
	int n, s[52];
	char s1[52], s2[52];
	cin >> n;

	scanf("%s", s1);

	scanf("%s", s2);

	int j=0;
	rep(i, n){
		if(s1[i] == s2[i]){
			s[j] = 1;
			j++;
		}else{
			s[j] = 2;
			j++;
			i++;
		}
	}
	ll sum =0;

	rep(i, j){
		if(i==0){
			if(s[i] == 1){
			sum += 3;
			}else{
				sum += 6;
			}
			continue;
		}
		if(s[i-1]==1 && s[i]==1){
			sum = sum * 2;
		}else if(s[i-1] == 2 && s[i] ==1 ){
			sum = sum;
		}else if (s[i-1] == 1 && s[i] ==2)
		{
			sum = sum * 2;
		}else{
			sum = sum * 3;
		}
	}

	cout << sum % 1000000007;
}
