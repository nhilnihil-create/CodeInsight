#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,sum=0;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int m;
    cin>>m;
    for (int j=0;j<m;j++){
        int a,b;
        cin>>a>>b;
        cout<<sum-arr[a-1]+b<<endl;
    }

	return 0;
}
