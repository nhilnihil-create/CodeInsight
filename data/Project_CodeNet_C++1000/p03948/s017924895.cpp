#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(void){
    int n, t;
    vector<int> a;
    map<int, int> p;
    cin >> n >> t;
    a.assign(n, 0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int mn = a[0];
    for(int i=1;i<n;i++){
        p[a[i]-mn]++;
        mn = min(mn, a[i]);
    }
    auto itr = p.end();
    itr--;
    cout << (itr->second) << endl;
}
