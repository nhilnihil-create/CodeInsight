#include<iostream>
#include<string>
using namespace std;
int S=0,T=0,sum=0;
string c;
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>c;
	for(int i=0;i<c.size();i++){
		if(c[i] == 'S'){
			S++;
			sum+=T;
			T=0;
		}
		else{
			if(S==0){
				T++;
			}else{
				S--;
			}
		}
	}
	sum+=S;
	cout<<sum;
	return 0;
}