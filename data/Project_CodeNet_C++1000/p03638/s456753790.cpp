#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
int a[200][200];
int h , w;
int main()
{

	cin >> h >> w;
	int n;
	cin >> n;
	int b[n + 1];
	for(int i = 1 ; i <= n ; i++)
	{
			cin >> b[i];
	}
	int num = 1,cnt = 1,x=1;
	for(int i = 1 ; i <= h ; i++){
		if(x % 2 == 1)
		{
			for(int j = 1 ; j <= w ; j++)
			{
					
					if(cnt > b[num]){
						num++;
						cnt=1;
					}
				    a[i][j] = num;
					cnt++;
			}
		}
		else
		{
			for(int j = w ; j >= 1 ; j--)
			{
					
					if(cnt > b[num]){
						num++;
						cnt=1;
					}
					a[i][j] = num;
					cnt++;
			}
		}
		//cout << endl;
		x++;
	}
	for(int i = 1 ; i <= h ; i++){
		for(int j = 1; j <= w ; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
} 


