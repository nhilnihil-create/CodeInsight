#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, l, n) for (int i = l; i < (int)(n); i++)
#define repn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
#define sort(v) sort(v.begin(), v.end())
#define sortr(v) sort(v.rbegin(), v.rend())
void chmin(int &a, int b) {if(a > b) a = b;}
void chmax(int &a, int b) {if(a < b) a = b;}

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


int main(){
    int h, w;
    cin >> h >> w;
    map<char, int> mp;
    rep(i,0,h)rep(j,0,w){
        char c;
        cin >> c;
        mp[c]++;
    }
    int num1 = (h%2)*(w%2);
    int num2 = (h/2)*(w%2)+(w/2)*(h%2);
    int n1 = 0, n2 = 0;
    for(auto it = mp.begin() ; it != mp.end() ; it++){
        if(it->second%4==1||it->second%4==3) n1++;
        if(it->second%4==2) n2++;
    }
    if(n1 == num1 && n2 <= num2) puts("Yes");
    else puts("No");
}