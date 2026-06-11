#include <bits/stdc++.h>
using namespace std;
 
long long n, x, y, arr[100005];
 
int main () {
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	sort(arr+1, arr+n+1);
    
    for(int i=n; i>0; i--){
        if(arr[i]==arr[i-1]){
            if(x==0){
                x=arr[i];
                i--;
            }
            else{
                y=arr[i];
                break;
            }
        }
    }
    
    cout<<x*y<<endl;
}