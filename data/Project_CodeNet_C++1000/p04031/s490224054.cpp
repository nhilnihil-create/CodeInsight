#include <iostream>
#include <vector>
using namespace std;
int main(void){
	int n;
	cin >> n;
	vector<int> arr;
	int x;
	int media=0;
	while(n--){
		cin >> x;
		arr.push_back(x);
		media+=x;
	}
	media/=arr.size();
	int minimo=10000000;
	for(int j=-100;j<=100;j++){
		int casox=0;
		for(int i=0;i<arr.size();i++){
			casox+=(arr[i]-j)*(arr[i]-j);
		}
		minimo = min(minimo,casox);
	}
	cout <<minimo << endl;
	return 0;
}