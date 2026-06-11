#include <iostream>

#include <deque>

#include <stdio.h>

#include <cstdio>

#include <algorithm>

#include<bits/stdc++.h>

#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define sp <<" "
#define nw <<"\n"
#define ca "Case "<<tc++<<": "
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define ull unsigned LL
#define check cout<<"* ";
#define show_vector for(int q=0;q<s.size();q++){cout<<s[q]<<" ";}
#define REP(i,n) for (int i=0;i<(n);++i)
#define N_MAX 26

const int inf=1<<30;
const long long int INF=1e10;
const int MOD=1e9+7;
const int maxn = 1e5+10;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int x;
    cin>>x;
    long long int low=0,high=1000000000,mid,sum,ans;
    while(low<=high){

        mid=(low+high) / 2;

        sum=(mid*(mid+1))/2;

        if(sum==x){
            ans=mid;
            break;
        }
        if(sum>x){
            ans=mid;
            high=mid-1;
        }
        if(sum<x){
            low=mid+1;
        }
    }

    cout<<ans nw;

}
