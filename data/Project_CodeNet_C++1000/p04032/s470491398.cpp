#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
//	cin>>n>>k;
//	cout<<n<<k<<endl;
//string S[100];

int main(){
	string moji;cin>>moji;

	bool flag=false;
	if (moji.size()==2){
		if (moji[0]==moji[1]){
			cout<<"1 2"<<endl;
			flag=true;

		}
	}else{

		int now,middle,end;
		for(int i=0;i<moji.size()-2;i++){
			now=i;middle=i+1;end=i+2;
			if (moji[now]==moji[middle]){
				cout<<now+1<<" "<<end+1<<endl;
				flag=true;break;
			}else if(moji[now]==moji[end]){
				cout<<now+1<<" "<<end+1<<endl;
				flag=true;break;
			}else if(moji[middle]==moji[end]){
				cout<<now+1<<" "<<end+1<<endl;
				flag=true;break;
			}
		}

	}
	if (flag==false){
		cout<<-1<<" "<<-1<<endl;
	}
	return 0;
}