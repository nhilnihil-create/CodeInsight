#include<bits/stdc++.h>
using namespace std;
int main(){
 	long long n,m;
    cin>>n>>m;
	long long answer=min(n,m/2);
	m=m-answer*2;
	answer=answer+m/4;
  	cout<<answer<<endl;
}
