#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>

void testcase(){
    int n,l;
    cin>>n>>l;
    string ans,s;
    vector<string> v;
    while(n--){
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(string x:v){
        ans+=x;
    }
    cout << ans << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}