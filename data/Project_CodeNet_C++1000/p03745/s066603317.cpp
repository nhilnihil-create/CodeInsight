#include<iostream>

using namespace std;

int arr[100005], fault[100005];

int main(){
    int N, ans = 1, temp = 0;
    cin >> N;
    for(int i=1; i<= N; i++){
        cin >> arr[i];
        if(i > 1){
            if(arr[i] > arr[i-1]){
                temp++;
                fault[temp] = 0;
            } else if (arr[i] < arr[i-1]){
                temp++;
                fault[temp] = 1;
            }
        }
    }
    for(int i=1; i<= temp-1; i++){
        if(fault[i] != fault[i+1]){
             ans++;
             i++;
        }
    }
    cout << ans << endl;
}