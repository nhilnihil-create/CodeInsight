#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
int a[512345];
int b[212345];
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>b[i];
	}
	int left =212345,right=left+1;
        for(int i=0;i<N;i++){
			if(i%2==(N-1)%2){
                a[left--]=b[i];
			}
			else{
				a[right++]=b[i];
			}
		}
		
		for(int i=left+1;i<right;i++){
			if(i!=left+1){
				cout<<" ";
			}
			cout<<a[i];
		}
		cout<<endl;
    return 0;
}