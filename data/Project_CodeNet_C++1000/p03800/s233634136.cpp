#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
//typedef tuple<ll, ll, ll> T;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin>>n>>s;
    bool a[4][101010] = {{false,false},{false,true},{true,false},{true,true}};
    for(int i=2;i<n;i++){
        for(int j=0;j<4;j++){
            a[j][i] = a[j][i-1] ^ a[j][i-2] ^ (s[i-1]=='o');
        }
    }
    int k=-1;
    for(int i=0;i<4;i++){
        if((s[n-1]=='o')==(a[i][n-2]^a[i][n-1]^a[i][0]) && (s[0]=='o') == (a[i][n-1]^a[i][0]^a[i][1])){
            k=i;
            break;
        }
    }
    if(k==-1){
        cout<<-1<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            cout<<"WS"[a[k][i]];
        }
        cout<<endl;
    }
    return 0;
}