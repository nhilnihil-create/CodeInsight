#include <bits/stdc++.h>
using namespace std;

string Y = "Possible";
string N = "Impossible";

int a[110];
int cnt[110] = {};
int main(){
    int n;
    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    sort(a, a+n);

    if(a[n-1] % 2 == 0){
        int c = 0;
        for(int i = a[n-1];i > a[n-1]/2;i--){
            if(cnt[i] < 2){
                cout << N << endl;
                return 0;
            }
            c += cnt[i];
        }
        if(cnt[a[n-1]/2] == 1 && c+1 == n){
            cout << Y << endl;
        }else{
            cout << N << endl;
        }
    }else{
        int c = 0;
        for(int i = a[n-1];i > a[n-1]/2+1;i--){
            if(cnt[i] < 2){
                cout << N << endl;
                return 0;
            }
            c += cnt[i];
        }
        if(cnt[a[n-1]/2+1] == 2 && c+2 == n){
            cout << Y << endl;
        }else{
            cout << N << endl;
        }
    }

    return 0;
}

