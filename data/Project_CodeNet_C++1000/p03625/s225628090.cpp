#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());
    long long int l1 = 0, l2 = 0;
    int i = 1;
    for(; i < n; i++){
        if(a[i-1] == a[i]){
            l1 = a[i];
            i += 2;
            break;
        }
    }
    for(; i < n; i++){
        if(a[i-1] == a[i]){
            l2 = a[i];
            break;
        }
    }
    cout << l1*l2 << endl;
    return 0;
}