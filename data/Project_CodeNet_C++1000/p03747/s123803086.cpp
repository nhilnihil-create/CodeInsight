#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
using namespace std;

const long long int INF=999999999999999;

long long int N,L,T,X[100005],W[100005],touch=0,after[100005],output[100005],zero;

int main() {
	cout << fixed << setprecision(5);
	cin>>N>>L>>T;
	for(int i=0;i<N;i++)
	{
		cin>>X[i]>>W[i];
		after[i]=(X[i]-(2*W[i]-3)*T)%L;
		after[i]=(after[i]+L)%L;
	}
	zero=after[0];
	for(int i=1;i<N;i++)
	{
		if(W[0]==1)
		{
			if(W[i]==2&&X[i]-X[0]<2*T)
			{
				touch+=1+(2*T-(X[i]-X[0])-1)/(L);
			}
		}
		
		if(W[0]==2)
		{
			if(W[i]==1&&L+X[0]-X[i]<=2*T)
			{
				touch+=1+(2*T+(X[i]-X[0]-L))/(L);
			}
		}
	}
	touch%=N;
	//cout<<touch<<endl;
	if(W[0]==2)touch=(5*N-touch)%N;
	//cout<<touch<<endl;
	sort(after,after+N);
	for(int i=0;i<N;i++)
	{
		if(after[i]==zero)
		{
			for(int j=0;j<N;j++)
			{
				output[(touch+j)%N]=after[(i+j)%N];
			}
			break;
		}
		//cout<<aft
	}
	for(int i=0;i<N;i++)
	{
		cout<<output[i]<<endl;
	}
}
