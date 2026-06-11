#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <locale>
using namespace std;
int main(){
	int N;
	vector<long long> arr;
	long long T;
	long long sumaT = 0;
	long long sumTmod;
	int M;
	int P;
	long long X;
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>T;
		arr.push_back(T);
		sumaT +=T;
	}
	cin>>M;
	
	for (int i = 1; i <= M; i++)
	{
		sumTmod = sumaT;
		cin>>P>>X;
		P -=1;
		if(arr[P] > X){
			long long resta;
			resta = arr[P] - X;
			
			sumTmod-=resta;
		}else if(arr[P]< X){
			long long suma;
			suma  = X - arr[P];
			sumTmod+=suma;
		}
		cout<<sumTmod;
		if(i<M){cout<<endl;}
	}
	
	
	
	return 0;
}