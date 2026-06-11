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
	
	int n,t;
	cin>>n>>t;
	
	string str[n],ans;
	for(int i=0 ; i<n ; i++)
	{
		cin>>str[i];
	}
	
	sort(str,str+n);
	
	for(auto it:str){
		ans+=it;
	}
	
	cout<<ans;
}

