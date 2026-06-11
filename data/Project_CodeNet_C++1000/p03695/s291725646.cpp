#include <iostream>
using namespace std;

int main() {
	//int scores[8]={399,799, 1199, 1599, 1999, 2399, 2799, 3199};
	//string colors[8]={"gray","brown", "green", "cyan", "blue", "yellow","orange","red"};
	int colo[9]={};
	int n;
	cin>>n;
	int arr[n];
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	for (int i=0; i<n; i++){
		if (arr[i]<=399) colo[0]++;
		else if (arr[i]<=799) colo[1]++;
		else if (arr[i]<=1199) colo[2]++;
		else if (arr[i]<=1599) colo[3]++;
		else if (arr[i]<=1999) colo[4]++;
		else if (arr[i]<=2399) colo[5]++;
		else if (arr[i]<=2799) colo[6]++;
		else if (arr[i]<=3199) colo[7]++;
		else colo[8]++;
	}
	int total=0;
	for (int i=0; i<8; i++){
		//cout << colo[i];
		if (colo[i]>0) total++;
	}
	//cout << endl;
	if (colo[8]==0)
		cout << total << ' ' << total << endl;
	else{ 
		if ( total>0 ) cout << total << ' ' << total+colo[8] << endl; 
		else cout << 1 << ' ' << colo[8] << endl; 
	} 
}