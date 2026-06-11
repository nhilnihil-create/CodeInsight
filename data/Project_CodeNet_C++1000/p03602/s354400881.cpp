#include <bits/stdc++.h>
#define maxn 310
using namespace std;
int arr[maxn][maxn];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	bool isedge[maxn][maxn];
	int n; cin>>n;
	for (int i = 0; i < n; ++i)
		for(int j = 0; j < n; j++){
			cin>>arr[i][j];
			isedge[i][j] = true;
		}
	bool error = false;

	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; j++){
			if(i >= j) continue;
			for(int k = 0; k < n; k ++){
				if(i == k || j == k)
					continue;
				if(arr[i][k] + arr[k][j] < arr[i][j])
					error = true;
				if(arr[i][k] + arr[k][j] == arr[i][j])
					isedge[i][j] = false;
			}
		}
	}
	if(error){
		cout<<"-1\n";
		return 0;
	}
	long long answer = 0;
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; j++){
			if(i < j && isedge[i][j])
				answer += arr[i][j];
			// cout<<isedge[i][j]<<" ";
		}
		// cout<<"\n";
	}
	cout<<answer<<endl;
	return 0;
}