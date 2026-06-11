#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N;
  	vector<int> A(N);
  	double sum=0.0;
  	for(int i=0; i<N ; i++){
    	cin >> A.at(i);
      	sum+= A.at(i);
    }
  	double ave = sum / N;
  	
  	int i_ave;
  	if(ave >=0){i_ave = (ave + 0.5);}
  	else{i_ave = (ave - 0.5);} 
  	int ans=0;
  	for(int i=0; i< N ;i++){
    	ans+=pow(i_ave-A.at(i),2);
    }
  	cout << ans << endl;
  	
}