#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n);
using namespace std;
int ar[1000000];
int arr[1000000];
int main()
{
	MaRiaMa;
	string s;
	cin >> s;
	int k = 0, j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A')
		{
			ar[k] = i ;
			k++;
		}
		else if (s[i] == 'Z')
		{
			arr[j] = i ;
			j++;
		}
	}
	cout <<(*max_element(arr,arr+j)-*min_element(ar,ar+k))+1;
}