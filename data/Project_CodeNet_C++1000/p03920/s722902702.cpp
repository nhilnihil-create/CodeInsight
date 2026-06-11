#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int N;
	cin>>N;
	if (N==1){
		cout<<1<<endl;
		return 0;
	}
	int i;
	int s=0;
	for (i=1;i<N;i++){
		if (i*(i+1)>=2*N){
			break;
		}
	}

	int Min=1;
	int Max=i;
	s = Max;
	i=Max-1;
	while (i>0){
		if (i+s<=N){
			cout<<i<<endl;
			s+=i;
		}
		i--;
	}
	cout<<Max<<endl;
	return 0;
}