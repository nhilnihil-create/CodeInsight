 #include <bits/stdc++.h>
using namespace std;

int main(){
    int n=0;
    cin >> n;
    int l=0;
    cin >> l;
    string arr[n]={};
    for(int i=0;i<n;i++){
    	cin >> arr[i];
    }
    sort(arr,arr+n);
    string ans;
    for(int i=0;i<n;i++){
    	ans+=arr[i];
    }
    cout << ans << endl;
	return 0;
}