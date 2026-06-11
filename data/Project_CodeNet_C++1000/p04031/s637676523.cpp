#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n ,result = 1e32;
    cin >> n ;
    int arr[n];
    for(int i=0 ; i<n ; i++)
        cin >> arr[i];

    sort(arr,arr+n);

    for(int i=arr[0] ;i<=arr[n-1]; i++){
        int sum = 0 ;
        for(int j=0 ; j<n ; j++){
            sum += (arr[j] - i) * (arr[j] - i) ;
        }
        if(sum < result){
            result = sum;
        }
    }

    cout << result ;
    return 0;
}
