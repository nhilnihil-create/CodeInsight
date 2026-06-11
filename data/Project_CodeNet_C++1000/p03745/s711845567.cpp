#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N; cin >> N;
    int a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    int cnt=1;
    char sign;
    char cur='=';
    for(int i=1;i<N;i++){
        if(a[i]>a[i-1]) sign='+';
        else if(a[i]<a[i-1]) sign='-';
        else continue;

        if(sign!=cur&&cur!='='){
            cnt++;
            cur='=';
            continue;
        }
        cur=sign;
    }
    cout << cnt << endl;
}