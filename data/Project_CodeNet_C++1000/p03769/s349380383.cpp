#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    n++;
    vector<int> ans;
    int k = 0, l;
    if(n & 1) k++;
    for(l = 1; l < 100; l++){
        if((1ll << l) > n) break;
        if((n >> l) & 1) k++;
        ans.push_back(l);
    }
    int j;
    for(j = l; j < l + k - 1; j++){
        ans.push_back(j);
    }
    j--;
    for(int i = 0; i < l - 1; i++){
        if((n >> i) & 1){
            ans.push_back(j);
            j--;
        }
        ans.push_back(i + 1);
    }
    cout << (int)ans.size() << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;
}