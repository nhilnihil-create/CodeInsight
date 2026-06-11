#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
//12:34
int main(){
	string s;
	cin>>s;
	int head,cnt,max,min=s.size();
	for(char c='a';c<='z';c++){
		head=0;
		cnt=0;
		max=0;
		while(head<s.size()){
			if(s[head]==c){
				cnt=0;
			}else{
				cnt+=1;
				if(max<cnt)max=cnt;
			}
			head++;
		}
		if(min>max)min=max;
	}
	cout<<min<<endl;
	return 0;
}