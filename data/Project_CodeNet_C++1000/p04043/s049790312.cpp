#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>

void testcase(){
    int a,b,c;
    cin>>a>>b>>c;
    if((a == 5 && b == 5 && c==7) ||(a == 5 && b == 7 && c==5) || (a == 7 && b == 5 && c==5)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}