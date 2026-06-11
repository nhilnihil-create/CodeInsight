#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    int n;
    cin >> n;
    vector<int> data(n);
    rep(i,0,n){
        cin >> data.at(i);
    }
    set<int> color;
    int over=0;
    rep(i,0,n){
        if(data[i]<400){
            color.insert(1);
        }else if(data[i]<800){
            color.insert(2);
        }else if(data[i]<800){
            color.insert(2);
        }else if(data[i]<1200){
            color.insert(3);
        }else if(data[i]<1600){
            color.insert(4);
        }else if(data[i]<2000){
            color.insert(5);
        }else if(data[i]<2400){
            color.insert(6);
        }else if(data[i]<2800){
            color.insert(7);
        }else if(data[i]<3200){
            color.insert(8);
        }else{
            over++;
        }
    }
    if(color.size()==0){
        cout<<1<<" "<<over<<endl;
    }else{
        cout<<color.size()<<" "<<color.size()+over<<endl;
    }
    
    
  return 0;
}