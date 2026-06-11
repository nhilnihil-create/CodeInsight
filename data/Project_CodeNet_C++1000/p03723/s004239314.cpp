#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;
    cin>>a>>b>>c;

    for(int i=0; i<1e7; i++){
        if(a%2==1 || b%2==1 || c%2==1){
            cout<<i<<endl;
            return 0;
        }

        int x=(b+c)/2;
        int y=(a+c)/2;
        int z=(b+a)/2;

        a=x;
        b=y;
        c=z;
    }
    cout<<-1<<endl;
}