#include<bits/stdc++.h>
using namespace std ;

const int MAXN = 1e5 + 100 ; 

int n , a[MAXN] ; 

int main()
{
	cin >> n ; 
	for(int i=1 ; i<=n ; i++)
		cin >> a[i] ;
	sort(a+1 , a+n+1) ; 
	reverse(a+1 ,a+n+1); 
	int pos = 1 ;  
	for(;pos<=n ; pos++)
		if(a[pos]<pos)
			break ; 
	pos-- ; 
//	cout << pos << endl ; 
	int pos2 = pos ; 
	for(;pos2<=n ; pos2++)
		if(a[pos2] < pos)
			break ; 
	pos2--;
//	cout << pos2 << endl ; 
	cout << ( ((pos2-pos)%2||(a[pos]-pos)%2) ? "First" : "Second" )<< endl ; 
	
}