#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        int temp;
        vector<int> arr;
        for(int i = 0; i < 2*n; i++){
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        int sum = 0;
        for(int i = 2*n - 1; i >= 0; i--){
            if(i % 2 != 0){
                sum += arr[i];
            }
        }
        cout << sum << endl;
    }
}