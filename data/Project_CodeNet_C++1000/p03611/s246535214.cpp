#include <bits/stdc++.h>
using namespace std;
int x, n, temp, j, maxi, hasil;
int arr[100001];
int frek[100001];
int main(){
	cin >> n;

	for (int i = 1 ; i<= n; i++){
		cin >> arr[i];
        frek[arr[i]]++;
		if (arr[i] > maxi){
			maxi = arr[i];
		}
	}
	sort(arr+1, arr+1+n);
	for (int i = 0; i <= maxi;i++){
		temp = frek[i] + frek[i-1] + frek[i+1];
		if (temp > hasil){
			hasil = temp;
		}
	} 
	
	cout <<  hasil << endl;	

	return 0;
}
