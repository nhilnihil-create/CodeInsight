#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> backet(MAX+1, 0);
    for(int i = 0; i < n; i++) backet[a[i]]++;

    int ansmax = 0;
    int ans = 0;
    for(int i = 0; i <= MAX; i++){
        if(i-3 >= 0) ans -= backet[i-3];
        ans += backet[i];
        if(ansmax < ans) ansmax = ans;
    }
    cout << ansmax << endl;
    return 0;
}