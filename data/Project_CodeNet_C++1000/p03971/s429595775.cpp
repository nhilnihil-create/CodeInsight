#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	int n,a,b,passed,b_rank;
	string s;

	cin>>n>>a>>b;
	cin>>s;

	
	b_rank=0;
	passed=0;
	for(auto& letter:s){
		if(passed < a+b){
			if(letter=='a'){
				passed++;
				cout<<"Yes\n";
				}	
			else if(letter=='b'){
				b_rank++;
				if(b_rank <= b){
					passed++;
					cout<<"Yes\n";
				}
				else
					cout<<"No\n";
			}
			else
				cout<<"No\n";
		}
		else
			cout<<"No\n";
	}

	return 0;

}