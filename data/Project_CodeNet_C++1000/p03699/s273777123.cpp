#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
int main(){
    int n;
    cin >> n;
    vector<int> data(n);
    int sum = 0;
    rep(i,0,n){
        cin >> data[i];
        sum += data[i];
    }
    if(sum%10!=0){
        cout<<sum<<endl;
    }else{
        sort(data.begin(),data.end());
        rep(i,0,data.size()){
            if(data[i]%10!=0){
                sum-=data[i];
                cout<<sum<<endl;
                return 0;
            }
        }
        cout<<0<<endl;
    }
    
    

  return 0;
}