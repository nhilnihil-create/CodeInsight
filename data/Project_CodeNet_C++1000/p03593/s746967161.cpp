#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

int main(){
    int h,w;
    cin>>h>>w;
    string s;
    vi data(26,0);
    rep(i,h){
        cin>>s;
        rep(j,w){
            data.at(s.at(j)-97)++;
        }
    }
    if(h%2==0&&w%2==0){
        bool flag=true;
        rep(i,26){
            if(data.at(i)%4!=0){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    else if(h%2==1&&w%2==1){
        int c1=0;
        int c2=0;
        rep(i,26){
            if(data.at(i)%2==1){
                c1++;
                if(data.at(i)%4==3) c2++;
            }else if(data.at(i)%4!=0){
                c2++;
            }
        }
        if(c1!=1){
            cout<<"No"<<endl;
            return 0;
        }
        int p=((h+w-2)/2)%2;
        if(((h+w-2)/2)>=c2&&p==(c2%2)){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else if(h%2==0&&w%2==1){
        int c2=0;
        rep(i,26){
            if(data.at(i)%2==1){
                cout<<"No"<<endl;
                return 0;
            }else if(data.at(i)%4!=0){
                c2++;
            }
        }
        if(c2<=h/2&&c2%2==(h-2)%2){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else{
        swap(h,w);
        int c2=0;
        rep(i,26){
            if(data.at(i)%2==1){
                cout<<"No"<<endl;
                return 0;
            }else if(data.at(i)%4!=0){
                c2++;
            }
        }
        if(c2<=h/2&&c2%2==(h-2)%2){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}