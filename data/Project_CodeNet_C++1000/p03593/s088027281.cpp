#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

int main(){
    int h,w;
    cin>>h>>w;
    char a[h][w];
    int num[26] = {};

    bool ok = true;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            num[a[i][j] - 'a']++;
        }
    }

    for(int i=0;i<h/2;i++){
        for(int j=0;j<w/2;j++){
            for(int k=0;k<26;k++){
                if(num[k]>=4){
                    num[k] -= 4;
                    break;
                }
            }
        }
    }

    if(h%2==1 && w%2==0){
        for(int i=0;i<w/2;i++){
            for(int j=0;j<26;j++){
                if(num[j]>=2){
                    num[j] -= 2;
                    break;
                }
            }
        }
    }
    if(h%2==0 && w%2==1){
        for(int i=0;i<h/2;i++){
            for(int j=0;j<26;j++){
                if(num[j]>=2){
                    num[j] -= 2;
                    break;
                }
            }
        }
    }
    if(h%2==1 && w%2==1){
        for(int i=0;i<h/2;i++){
            for(int j=0;j<26;j++){
                if(num[j]>=2){
                    num[j] -= 2;
                    break;
                }
            }
        }
        for(int i=0;i<w/2;i++){
            for(int j=0;j<26;j++){
                if(num[j]>=2){
                    num[j] -= 2;
                    break;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(num[i]>=1){
                num[i] -= 1;
                break;
            }
        }
    }

    for(int i=0;i<26;i++){
        if(num[i] > 0) ok =false;
    }

    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}