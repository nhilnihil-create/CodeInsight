#include <iostream>
using namespace std;
int fpb(int n, int m){
    if(m==0){
        return n;
    }
    else{
        return fpb(m, n%m);
    }
}
int main(){
    int n, k, arr[100005], temp, max=0;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i]; 
        if(max<arr[i]){
            max=arr[i];
        }
    }
    temp=arr[1];
    for(int i=2; i<=n; i++){
        temp=fpb(temp, arr[i]);
    }
    if(k>=temp && k%temp==0 && k <= max){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}