#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<vector<ll>> nikou_table(ll n){
    vector<vector<ll>> mat(n+1, vector<ll> (n+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i) mat[i][j] = 1;
            else mat[i][j] = mat[i-1][j-1]+mat[i-1][j];
        }
    }
    return mat;
}

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<long double> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end(),greater<>());
    long double avg=0.0;
    map<ll,int> used;
    for(int i=0; i<a; i++){
        avg+=v[i];
        used[v[i]]++;
    }
    avg/=a;
    cout<<fixed<<setprecision(15)<<avg<<endl;
    
    //0~aまでが同じ数の場合
    //v[a]からv[j]までが同じとき、組み合わせは？
    //aからjまで同じなので、jCi(a<=i<=j)でできそう

    //同じ数でなかったら平均値となる集合の要素と同じものがあればいいので、これはできる
    for(int i=0; i<n; i++){
        //cout<<i<<" "<<v[i]<<endl;
    }
    if(v[0]==v[a-1]){
        ll ans=0;
        bool ok=true;
        int j=b;
        for(int i=a-1; i<n; i++){
            if(v[i]!=v[i+1]){
                j=i+1;
                break;
            }else j=i+1;
        }
        vector<vector<ll>> c=nikou_table(j);
        for(int i=a; i<=b; i++){
            //cout<<ans<<endl;
            if(i>j) continue;
            ans+=c[j][i];
        }
        cout<<ans<<endl;
    }else{
        ll ans = 1;
        map<ll,int> m,m2;
        for(int i=0; i<a; i++){
            m[v[i]]++;
        }
        for(int i=0; i<n; i++){
            m2[v[i]]++;
        }
        for(auto i:m){
            vector<vector<ll>> c=nikou_table(m2[i.first]+i.second);
            ans *= c[m2[i.first]][i.second];
            //cout<<m2[i.first]<<" ";
        }
        cout<<ans<<endl;
    }

}