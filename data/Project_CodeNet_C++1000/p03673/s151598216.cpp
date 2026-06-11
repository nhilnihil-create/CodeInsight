#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}


int main(){
    int n;
    cin >> n;
    vector<int> odd, even;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(i%2 == 1) odd.push_back(a);
        else even.push_back(a);
    }

    vector<int> ans;
    if(n%2 == 1){
        for(int i = odd.size()-1; i >= 0; i--) ans.push_back(odd[i]);
        for(int i = 0; i < even.size(); i++) ans.push_back(even[i]);
    }
    else{
        for(int i = even.size()-1; i >= 0; i--) ans.push_back(even[i]);
        for(int i = 0; i < odd.size(); i++) ans.push_back(odd[i]);
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
