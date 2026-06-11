    #include<iostream>
    #include<stdio.h>
    //#include <bits/stdc++.h>
    #include<vector>
    #include<float.h>
    #include<iomanip>
    #include<algorithm>
    #include<string>
    #include<cstring>
    #include<math.h>
    #include<cmath>
    #include<sstream>
    #include<set>
    #include<map>
    #include<queue>
    #include<cassert>
    #include<cmath>
    #include<cstdint>
     
    #define INF 1e9
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
    #define chmin(a, b) a = min(a, b)
    #define chmax(a, b) a = max(a, b)
    #define pb push_back
    #define sz size()
     
    using namespace std;
    using ll = long long int;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
    using Vl = vector<ll>;
     
const int MOD = 1e9 + 7;
const ll ZER = 0;

//bit全探索
vector<ll>bitSearch(int bit,int n){
    vector<ll>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    S.push_back(1e9);
    return S;
}

ll dp1[3010][2], dp2[3010][2];
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, 0);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;b--;
        cnt[a]++;
        cnt[b]++;
    }
    rep(i, n){
        if(cnt[i] % 2 != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

