#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    //freopen("E:\\Codes\\Problem\\C++\\AAA.txt", "r", stdin);
    //freopen("C:\\Users\\Dell\\Desktop\\Problem\\BBB.txt", "w", stdout);
	
	int n,k;
	cin>>n>>k;
	
	int arr[k];
	
	for(int i=0 ; i<k ; i++){
		cin>>arr[i];
	}
	
	while (true)
	{
		int fg=1;
		int tp=n;
		
		while(tp) //1000
		{
		int tck=tp%10;
		for(int i=0 ; i<k ; i++)
			{
			if(tck==arr[i])
				{
					fg=-1;
					break;
				}
			
			} 
		tp/=10;

		}
		
	if(fg==1)
	{
		cout<<n;
		return 0;
	}
	n++;
	
		
}
	
	

}

