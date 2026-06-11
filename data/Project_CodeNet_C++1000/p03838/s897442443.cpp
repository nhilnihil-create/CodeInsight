#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000

int main()
{
    ll x,y;
    cin >> x >> y;
    if(abs(x)==abs(y)){
        if(x+y==0){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        ll count=0;
        if(abs(x)<abs(y)){
            count+=abs(y)-abs(x);
            if(x<0&&y>0){
                count++;
            }else if(x<0&&y<0){
                count+=2;
            }else if(x>=0&&y<0){
                count++;
            }
        }else{
            count+=abs(x)-abs(y);
            if(x>0&&y>0){
                count+=2;
            }else if(x>0&&y<=0){
                count+=1;
            }else if(x<0&&y>0){
                count++;
            }
        }
        cout << count << endl;
    }
}