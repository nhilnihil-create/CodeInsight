#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    if(h%a==0&&w%b==0){
        cout<<"No";
        return 0;
    }
    cout<<"Yes"<<endl;
    if(w%b){
        rep(i,h){
            rep(j,w){
                if(j%b==0)cout<<(b-1)*10000-1<<' ';
                else cout<<-10000<<' ';
            }
            cout<<endl;
        }
    }
    else{
        rep(i,h){
            rep(j,w){
                if(i%a==0)cout<<(a-1)*10000-1<<' ';
                else cout<<-10000<<' ';
            }
            cout<<endl;
        }
    }
	return 0;
}
