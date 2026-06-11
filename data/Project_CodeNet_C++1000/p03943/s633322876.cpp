#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    int mx = max(a, max(b, c));
    if(sum - mx == mx){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
