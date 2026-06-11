#include<iostream>
#include<vector>

int main(){
	long long answer=1;
	long long mod= 1000000007;

	int n;
	std::vector<int> tList;
	std::vector<int> aList;

	std::vector<bool> isNewT;
	std::vector<bool> isNewA;

	std::cin>>n;

	tList.resize(n);
	aList.resize(n);
	isNewT.resize(n, false);
	isNewA.resize(n, false);

	isNewT[0]= true;
	isNewA[n-1]= true;

	for(int i=0; i<n; i++)
		std::cin>>tList[i];
	for(int i=0; i<n; i++)
		std::cin>>aList[i];

	for(int i=1; i<n; i++)
		if(tList[i-1]<tList[i])
			isNewT[i]=true;

	for(int i=1; i<n; i++)
		if(aList[n-1-i]>aList[n-i])
			isNewA[n-1-i]=true;

	for(int i=0; i<n; i++){
		if(isNewT[i] && isNewA[i]){
			if(tList[i]!=aList[i]){
				answer=0;
				break;
			}
		}
	
		if(isNewT[i] && !isNewA[i]){
			if(tList[i]> aList[i]){
				answer=0;
				break;
			}
		}

		if(!isNewT[i] && isNewA[i]){
			if(tList[i]< aList[i]){
				answer=0;
				break;
			}
		}

		if(!isNewT[i] && !isNewA[i]){
			answer*= std::min(tList[i], aList[i]);
			answer= answer% mod;
		}

	}


	std::cout<<answer<<std::endl;

	return 0;
}