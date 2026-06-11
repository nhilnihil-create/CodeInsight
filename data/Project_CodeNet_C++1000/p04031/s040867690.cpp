#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n ,result = 8888888;
    cin >> n ;
    int arr[n];
    for(int i=0 ; i<n ; i++)
        cin >> arr[i];

    for(int i= -100 ; i<101 ; i++){
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
