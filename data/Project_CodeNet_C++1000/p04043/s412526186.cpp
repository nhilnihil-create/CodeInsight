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
	
	int arr[3],f5=0 , s7=0;
	for(int i=0 ; i<3 ; i++){
		cin>>arr[i];
	}
	
	for(auto it : arr){
		if(it==5)f5++;
		else if(it==7)s7++;
	}
	if(f5==2 && s7 ==1)
		cout<<"YES"<<endl;
	else{
		cout<<"NO"<<endl;
	}
}

