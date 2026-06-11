
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll nums[7];
ll ans = 0;
ll shapes[3];

int main(void) {
    // insert code here...
    for(int i = 0; i < 7; i++){
        cin >> nums[i];
    }
    
    ans += nums[1];
    shapes[0] = nums[0];
    shapes[1] = nums[3];
    shapes[2] = nums[4];
    
    sort(shapes, shapes+3);
    
    ans += shapes[0] * 3;
    ll a,b;
    
    a = shapes[1] - shapes[0];
    b = shapes[2] - shapes[0];
    
    if(shapes[0]!= 0){
        if(a%2==0 && b%2==0){
            ans += a + b;
        }else{
            ans += a + b - 1;
        }
    }else{
        ans += (a/2)*2 + (b/2)*2;
    }
    
    cout << ans << endl;
    
    return 0;
}
