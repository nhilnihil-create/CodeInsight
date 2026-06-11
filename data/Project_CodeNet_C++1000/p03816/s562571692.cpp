#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    for(int n=0; n<N; n++) {
        int A;
        cin >> A;
        mp[A]++;
    }
    
    int ans=mp.size();
    int cnte=0;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
        if(itr->second%2==0) {
            cnte++;
        }
    }
    
    if(cnte%2!=0) {
        ans--;
    }
    
    cout << ans << endl;
    

    return 0;
    
}