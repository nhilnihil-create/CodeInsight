#include <iostream>
using namespace std;

int main(){
    int n, arr[100005], sum=1, flex=0, i=0;
    cin >> n;
    for(i=1; i<=n; i++){
        cin >> arr[i];
    }
    i=2;
    while(i<=n){
        if(arr[i]<arr[i-1] && flex==1){
            sum++;
            flex=0; 
        }
        else if(arr[i]>arr[i-1] && flex==-1){
            sum++;
            flex=0;
        }
        else{
            if(arr[i]>arr[i-1]){
                flex=1;
            }
            else if(arr[i]<arr[i-1]){
                flex=-1;
            }
        }
        i++;
    }
    cout << sum << endl;
    return 0;
}