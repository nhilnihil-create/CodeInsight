#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll nums[3], cnt = 0, tmp[3];
    for (int i=0; i<3; i++) cin >> nums[i];
    if (nums[0]%2==0 && nums[0] == nums[1] && nums[1] == nums[2]){
        cout << -1 << endl;
    } else{
        while (nums[0]%2==0 && nums[1]%2==0 && nums[2]%2==0){
            cnt++;
            for (int i=0; i<3; i++) tmp[i] = nums[i] / 2;
            nums[0] = tmp[1] + tmp[2];
            nums[1] = tmp[0] + tmp[2];
            nums[2] = tmp[0] + tmp[1];
        }
        cout << cnt << endl;
    }
    return 0;
}