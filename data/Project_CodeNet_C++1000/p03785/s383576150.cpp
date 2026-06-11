#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, c, k, arr[100005], range, capa=0, bus=0;
    cin >> n >> c >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    range=arr[1]+k;
    capa++;
    bus++;
    for(int i=2; i<=n; i++){
        if(arr[i]<=range && capa<c) {
            capa++;
        }
        else{
            range=arr[i]+k;
            capa=1;
            bus++;
        }
    }
    cout << bus << endl;
    return 0;
}