#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    //freopen("E:\\Codes\\Problem\\C++\\AAA.txt", "r", stdin);
    //freopen("C:\\Users\\Dell\\Desktop\\Problem\\BBB.txt", "w", stdout);
	
	int a,b;
	char k;
	cin>>a>>k>>b;
	
	if(k=='+'){
		cout<<a+b<<endl;
	}
	else{
		cout<<a-b<<endl;
	}

}

