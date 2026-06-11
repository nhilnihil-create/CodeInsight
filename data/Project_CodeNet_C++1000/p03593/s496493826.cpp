#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const long long INF = 1LL<<60;

char f[110][110];
int m[26];

int main() {
    int h,w;
    cin>>h>>w;
    
    rep(i,h){
        rep(j,w){
            cin>>f[i][j];
            m[f[i][j]-'a']++;
        }
    }

    if(h%2==0 && w%2==0){
        rep(i,26){
            if(m[i]%4!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    }
    else if(h%2==0 && w%2==1){
        rep(i,(h*w-h)/4){
            rep(j,26){
                if(m[j]>=4){
                    m[j]-=4;
                    break;
                }
                if(j==25){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        rep(i,h/2){
            rep(j,26){
                if(m[j]%2!=0){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        cout<<"Yes"<<endl;
    }
    else if(h%2==1 && w%2==0){
        rep(i,(h*w-w)/4){
            rep(j,26){
                if(m[j]>=4){
                    m[j]-=4;
                    break;
                }
                if(j==25){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        rep(i,w/2){
            rep(j,26){
                if(m[j]%2!=0){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        cout<<"Yes"<<endl;
    }
    else{
        rep(i,(h*w-w-h+1)/4){
            rep(j,26){
                if(m[j]>=4){
                    m[j]-=4;
                    break;
                }
                if(j==25){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        rep(i,(w-1)/2){
            rep(j,26){
                if(m[j]>=2){
                    m[j]-=2;
                    break;
                }
                if(j==25){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        rep(i,(h-1)/2){
            rep(j,26){
                if(m[j]>=2){
                    m[j]-=2;
                    break;
                }
                if(j==25){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        cout<<"Yes"<<endl;
    }
}