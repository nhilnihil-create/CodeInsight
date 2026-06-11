#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	char x;
	//scanf("%s", x);
	int to = a+b;
	int passed = 0, overseas = 0;
	for(int i=0; i<n; i++){
		cin >> x;
		if(x=='a'){
			if(passed<to){
				cout << "Yes\n";
				passed++;
			}
			else{
				cout << "No\n";
			}
		}
		else if(x=='b'){
			if(passed<to && overseas<b){
				cout << "Yes\n";
				passed++;
				overseas++;
			}
			else{
				cout << "No\n";
			}
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}
