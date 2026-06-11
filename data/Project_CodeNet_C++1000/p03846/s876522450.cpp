#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

const int MOD=1e9+7;

bool is_possible(vector<int> row){
	vector<int> numbers(row.size(),0);
	//for (int i: numbers) printf("%d",i);
	for (int i: row){
		if (numbers[i/2] == 0) numbers[i/2]+=1;
		else if (numbers[i/2] == 1 && i != 0) numbers[i/2]+=1;
		else if (numbers[i/2] == 2) return false;
		else return false;

	}
	
	return true;
}
int main(){
    
    int n;
    scanf("%d",&n);
	vector<int> row(n);
	for (int&k : row){
		scanf("%d",&k);
	}
	if (is_possible(row)){
		long long result = 1;
		for (int i=0; i<n/2;i++){
			result=2*result%MOD;
		}
		
		printf("\n%lld",result);
	}
	else printf("\n%d",0);
    return 0;
}
