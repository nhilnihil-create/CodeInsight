#include <iostream>
using namespace std;
#include <algorithm>

int main(void){
    // Your code here!
    int n,k;
    cin >> n >> k;
    int sum = 0;
    int a[60];
    
    for(int i=0; i<n; i++) cin >> a[i];
    
     sort(a, a + n, greater<int>());
     
     for(int i=0; i<k; i++) sum+= a[i];
    
    cout << sum << endl;
}
