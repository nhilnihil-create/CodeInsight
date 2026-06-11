#include<bits/stdc++.h>
using namespace std;

int main()
{
	
		int m[100000+5]={0};
		int max1=0;
		int a;
		int n;
		cin>> n;
		for(int i=0;i<n;i++){
			cin >> a;
			m[a+1]++;
			max1=max(m[a+1],max1);
			if(a!=0){
				m[a-1]++;
				max1=max(m[a-1],max1);
			}
			m[a]++;
			max1=max(m[a],max1);
		}
		cout << max1 << endl;
	
 } 