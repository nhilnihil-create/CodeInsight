#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int arr[N];
	int count[100001]={0};
	int x=0; int y=0;
	for (int i=0; i<N; i++){
		cin >> arr[i];
	}
	for (int i=0; i<N; i++){
		count[arr[i]]++;
	}
	int total=0;
	for (int i=0; i<100001; i++){
		if (count[i]){
			total++;
			if (count[i]%2==0) x++;
		}
	}
	if (x%2) cout << total-1 << endl;
	else cout << total << endl;
}
