#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7;
int n, a[N], dp[100][100], was[100][100];
int get(int i,int j){
	if(was[i][j])
		return dp[i][j];
	was[i][j] = 1;
	if(a[i] <= j){
		dp[i][j] = 1;
		return dp[i][j];
	}
	if(i > 0)
		get(i - 1, j);
	get(i, j + 1);	
	if(i > 0 && dp[i - 1][j] == 0)
		dp[i][j] = 1;
	if(dp[i][j + 1] == 0)
		dp[i][j] = 1;
	return dp[i][j];
}
int main(){
	srand(time(0));

	n = 6;

	cin >> n;
	
	for(int i = 1; i <= n; i++)
		//a[i] = rand()%10 + 1 ;
		cin >> a[i];

	sort(a + 1, a + n + 1);
	
	int ans = 0;
	for(int i = n; i >= 0; i--){
		int x = n - i;
        if(x < a[i]){
			ans = a[i] - x + 1;
			//cerr << i << " " << x << " "<< a[i] << endl;
		}
        if(x == a[i]){
			int z = 0;
			for(int j = 0; j <= i; j++)
            	if(a[j] == a[i])
          	       	z++;
			if( (z % 2 == 0) && a[i] < a[i + 1] ){
				if( (a[i + 1] - a[i])&1 )
					ans = z + 1;
				else
					ans = z;		 
			}else
				ans = z;

		}
	}
	ans&=1;
	
	//cout << ans << endl;
    
    if(ans == 1)                    
		cout << "First" << endl;
    else
    	cout << "Second" << endl;
	
	return 0;
	cout << get(n,0) << endl;
	//return 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 20; j++){
			if(a[i] == j)
				cout<<"%";
            else
            	cout<<get(i,j);
		}
		cout<<endl;
	}
	return 0;
}
