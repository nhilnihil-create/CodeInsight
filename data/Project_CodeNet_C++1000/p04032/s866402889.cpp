#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    string s; cin >> s;
    int ans0=-1, ans1=-1;
    vector<int> last(26, -3);
    for(int i=0; i<s.size(); ++i){
        int j=s[i]-'a';
        int len=i-last[j]+1;
        if(len==2 || len==3){
            ans0=last[j]+1;
            ans1=i+1;
            break;
        }
        last[j]=i;
    }
    cout << ans0 << " " << ans1 << endl;
    return 0;
}
