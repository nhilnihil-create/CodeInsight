#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n >> s;
	int max = 0;
	int sum = 0;
	for(int i = 0; i<n; i++)
	{
		if(s[i] == 'I'){
			sum++;
			if(sum > max){
				max= sum;
			}
		}
		else{
			sum--;
		}
	}
	cout << max;
	
	return 0;
}