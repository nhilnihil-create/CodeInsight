#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){
    int n,m;
    cin >> n>> m;
    vector<vector<char>> A_field(n,vector<char>(n));
    vector<vector<char>> B_field(m,vector<char>(m));
    rep(i,0,n){
        string s;
        cin >> s;
        rep(j,0,n){
            A_field[i][j]=s[j];
        }
    }
    rep(i,0,m){
        string s;
        cin >> s;
        rep(j,0,m){
            B_field[i][j]=s[j];
        }
    }
    //cout<<B_field[0][0]<<endl;
    rep(i,0,n-m+1){
        rep(j,0,n-m+1){
            int check = 1;
            rep(k,0,m){
                rep(l,0,m){
                    if(A_field[i+k][j+l]!=B_field[k][l]){
                        check = 0;
                    }
                }
            }
            if(check){
                cout<<"Yes"<<endl;
                return 0;
            }
            
        }
    }
    cout<<"No"<<endl;
    

    return 0;
}
