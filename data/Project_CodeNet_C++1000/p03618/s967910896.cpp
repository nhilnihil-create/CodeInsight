#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n));
#define Vec(a,n) vector<string> (a)((n));
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0));
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a));
#define Reverse(a) reverse(All(a));
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl;
#define printD(a) cout << setprecision(15) << (a) << endl;
using namespace std;
int max_int = 1000000007;
double pi = 3.1415926535;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<int>& a,int n);

int n;

signed main(){
    string s;
    cin >> s;
    int cnt = 0;
    int n = s.size();
    REP(i,26){
        char c = i + 'a';
        int cnt1 = 0;
        REP(j,n){
            if(s[j] == c) cnt1++;
        }
        cnt += (cnt1*(cnt1-1))/2;
    }

    cout << (n*(n-1)/2)-cnt+1 << endl;
    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}
int nibul(auto a,auto b){
    int x = lower_bound(All(a),b) - a.begin();
    //key以上の初めてのitr
    return x;
}
int nibuu(auto a,auto b){
    int x = upper_bound(All(a),b) - a.begin();
    //key以下の最後のitr
    return x-1;
}

void input(vector<int>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}
