#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

mat memo(100,vec(100,-1));

ll comb(int i,int j){
    if(j==0)return 1;
    if(i==j)return 1;
    if(memo[i][j]!=-1)return memo[i][j];

    return memo[i][j]=comb(i-1,j)+comb(i-1,j-1);
}

int main(){
    int N,A,B;cin>>N>>A>>B;
    ll v[60],S[60];
    S[0]=0;
    map<ll,int> mp;
    for(int i=0;i<N;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    sort(v,v+N,greater<ll>());
    for(int i=0;i<N;i++)
        S[i+1]=S[i]+v[i];

    if(v[0]!=v[A-1]){
        int c=0,k=A-1;
        while(v[k]==v[A-1]){
            c++;
            k--;
        }
        double ans=(double)S[A]/(double)A;
        printf("%.8lf\n",ans);
        cout<<comb(mp[v[A-1]],c)<<endl;     
        return 0;
    }
    else{
        ll count=0;
        int c=A;
        for(int i=A;i<=B;i++){
            count+=comb(mp[v[0]],c);
            if(v[i]==v[0])c++;
            else break;
        }
        cout<<v[0]<<endl;
        cout<<count<<endl;
        return 0;
    }
    return 0;   
}