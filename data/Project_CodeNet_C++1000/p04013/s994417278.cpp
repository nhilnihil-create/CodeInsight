#include <iostream>

using namespace std;

int a[55];
long long dp[55][2505][55];

long long utility(int index, int sum, int count, int * a, int k)	{
	if (index < 0)
    	return 0;
    else if (index == 0)	{
    	if (count == 0)
        	return 0;
        int remainder = sum % count;
       	if (remainder)
        	return 0;
        else	{
        	int avg = sum / count;
            if (avg == k)
            	return 1;
            else
            	return 0;
        }
    }
    
    if (dp[index][sum][count] != -1)	{
    	return dp[index][sum][count];
    }
    
    long long include = utility(index - 1, sum + a[index - 1], count + 1, a, k);
    long long exclude = utility(index - 1, sum, count, a, k);
    long long total = include + exclude;
  	dp[index][sum][count] = total;
    return total;
}

long long ways(int n, int k)	{
	return utility(n, 0, 0, a, k);
}

int main()	{
  	int n, k;
    for (int i = 0; i < 55; i++)
    	for (int j = 0; j < 2505; j++)
        	for (int k = 0; k < 55; k++)
            	dp[i][j][k] = -1;
  	cin >> n >> k;
  	for (int i = 0; i < n; i++)	
      	cin >> a[i];
 	cout << ways(n, k);
  	return 0;
}