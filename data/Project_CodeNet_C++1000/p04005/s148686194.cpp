#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    vector<long long> arr(3);
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr.begin(), arr.end());
    long long ans = arr[0] * arr[1];

    if(arr[2] & 1) //odd
    	cout<<ans;
    else 
    	cout<<0;
	return 0;		
}
