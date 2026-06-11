#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    long long a[7];
    for(int i = 0; i < 7; i++){
        cin >> a[i];
    }
    long long ans1 = 0, ans2 = 0;
    ans1 += a[0]/2*2 + a[1] + a[3]/2*2 + a[4]/2*2;
    if((a[0] % 2) && (a[3] % 2) && (a[4] % 2)){
        ans1 += 3;
    }
    if(a[0] && a[3] && a[4]){
        ans2 = (a[0]-1)/2*2 + a[1] + (a[3]-1)/2*2 + (a[4]-1)/2*2 + 3;
    }
    cout << max(ans1, ans2) << endl;
}