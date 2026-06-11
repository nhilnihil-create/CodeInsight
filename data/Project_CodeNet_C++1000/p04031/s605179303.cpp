#include<bits/stdc++.h>
using namespace std;

#define ll long long int

	
	
int main(){
	
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int min = *min_element(arr,arr+n);
	int max = *max_element(arr,arr+n);
	
	int min_cost=  INT_MAX;
	int temp = 0;
	for(int i=min;i<=max;i++){
			temp =0;
			for(int j=0;j<n;j++){
				temp += (i - arr[j]) * (i - arr[j]);
				} 
			if(temp < min_cost)
				min_cost = temp;
	}
	
	cout<<min_cost<<endl;
}
