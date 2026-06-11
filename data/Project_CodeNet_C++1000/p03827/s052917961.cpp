#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define ll long long
#define coYes cout << "Yes" << endl
#define coYES cout << "YES" << endl
#define coyes cout << "yes" << endl
#define coNo cout << "No" << endl
#define coNO cout << "NO" << endl
#define cono cout << "no" << endl
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){ //最大公約数
    if(a%b == 0){
        return b;
    }else{
    return gcd(b, a%b);
    }
}

int main(){
    int n,x=0,temp=0;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    rep0(i,n){
        if(s[i]=='I'){ 
            x++;
            a.push_back(x);
        }
        else if(s[i]=='D'){ 
            x--;
            a.push_back(x);
        }
    }
    sort(a.begin(),a.end(),greater<int>());
    cout << a[0] << endl;
    return 0;
}