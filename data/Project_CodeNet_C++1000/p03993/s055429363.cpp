#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
          cin >> a[i];
    }
    long ans = 0;
    for(int i = 0;i < n;i++){
          if(i == a[a[i] - 1] - 1)ans++;
    }
    ans /= 2;
    cout << ans << endl;
}
