#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    string sa,sb,sc;
    cin>>sa>>sb>>sc;
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    reverse(sc.begin(), sc.end());

    char now=sa.back();
    sa.pop_back();
    while(1){
        if(now=='a'){
            if(sa.size()==0){
                cout<<'A'<<endl;
                break;
            }
            now=sa.back();
            sa.pop_back();
        }else if(now=='b'){
            if(sb.size()==0){
                cout<<'B'<<endl;
                break;
            }
            now=sb.back();
            sb.pop_back();
        }else{
            if(sc.size()==0){
                cout<<'C'<<endl;
                break;
            }
            now=sc.back();
            sc.pop_back();
        }
    }

    return 0;
}