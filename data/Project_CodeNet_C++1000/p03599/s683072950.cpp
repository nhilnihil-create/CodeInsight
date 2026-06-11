#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace __gnu_pbds;
using namespace std;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve(){
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    int mom=A*100,son=0;
    for(int a=0;a<=30;a++){
        for(int b=0;b<=30;b++){
            for(int c=0;c<=100;c++){
                for(int d=0;d<=100;d++){
                    if(a*A*100+b*B*100+c*C+d*D>F) continue;

                    int water=a*A*100+b*B*100;
                    int sugar=c*C+d*D;
                    if(100*sugar>E*water) continue;
                    //cout<<sugar<<" "<<water<<endl;
                    if((sugar*mom)>son*(sugar+water)){
                        son=sugar;
                        mom=sugar+water;
                    }

                }
            }
        }
    }
    cout<<mom<<" "<<son;

    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
