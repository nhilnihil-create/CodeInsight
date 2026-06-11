
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <time.h>

#define loop(i, num)  for (int i = 0; i < num; i++)

using namespace std;

int n, ans;

vector<int> nums;

int main() {
    
    cin >> n;
    
    nums.resize(n);
    
    loop (i, n) {
        
        cin >> nums[i];
        
    }
    
    for (int i = 0; i < n - 1; i++) {
        
        if (nums[i] == i + 1) {
            
            swap(nums[i], nums[i + 1]);
            
            ++ans;
            
            ++i;
            
        }
        
    }
    
    if (nums[n - 1] == n) {
        
        ++ans;
        
    }
    
    cout << ans << endl;
    
}
