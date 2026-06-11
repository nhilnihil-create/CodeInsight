#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	
		cin>>a[i];
	}
	int ans=0;
	int j=0;
	int x=a[0];
	vector<int> st;
	while(j+1!=2){
	
		ans++;
		j=x-1;
		for(int i=0;i<st.size();i++){
		
			if(st[i]==j){

				cout<<-1<<'\n';
				return 0;
			}
		}
		st.push_back(j);
		x=a[j];
		
	}
	cout<<ans<<'\n';
	return 0;
}
