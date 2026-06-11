#include<iostream>
#include<string>
using namespace std;
#define MOD 1000000007
int main(){
    int n;cin >> n;
    string u,d;cin >> u >> d;
    long long ans;
    bool ver;
    int i=0;
    if(u[0] == d[0]){
        ver = true;
        ans = 3;
        i++;
    }
    else{
        ver = false;
        ans = 3*2;
        i +=2;
    }
    while(i < n){
        if(ver && (u[i] == d[i])){
            ans = (ans*2)%MOD;
            ver = true;
            i++;
        }
        else if(ver && (u[i] != d[i])){
            ans = (ans*2)%MOD;
            ver = false;
            i += 2;
        }
        else if((!ver) && (u[i]== d[i])){
            ver = true;
            i ++;
        }
        else if((!ver) && (u[i] != d[i])){
            ans = (ans*3)%MOD;
            ver =false;
            i +=2;
        }
        else{
            cout << "error" << endl;
        }
    }
    cout << ans << endl;
    return 0;
}