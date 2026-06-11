 #include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n] = {};
    double sum = 0;
    for(int i=0;i<n;i++){
    	cin >> arr[i];
    	sum+=arr[i]; 
    }
    //cout << sum << endl;
    int lim = round(sum/n);
    //cout << lim << endl;
    int ans= 0;
    for(int i=0;i<n;i++){
    	ans+=((abs(arr[i]-lim))*(abs(arr[i]-lim)));
    }
    cout << ans << endl;
	return 0;
}