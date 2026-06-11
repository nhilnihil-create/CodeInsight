#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int>a(n);
	for(auto&& w:a)cin>>w;
	int num=0,ans=0;
	for(int i=0;i<n;i++){
		if(a[i]==i+1){num++;}
		else{
			if(num!=0)ans+=(num/2)+num%2;
			num=0;
		} 
    //  cout<<num<<" "<<ans<<endl;
	}
	if(num!=0)ans+=(num/2)+num%2;
                    
	cout<<ans<<endl;	
}
