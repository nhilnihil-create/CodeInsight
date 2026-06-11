// AGC 16 A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    string s; cin >> s;
    int len = s.length();
    int mi = INT_MAX;
    for(char it = 'a'; it <= 'z'; it++){
        int c = 0, cma = INT_MIN;
        for(int i = 0; i < len; i++){
            if(s[i] == it){
                cma = max(cma, c);
                c = 0;
            }else{
                c++;
            }
        }
        cma = max(cma, c);
        mi = min(mi, cma);
    }
    cout << mi << endl;
    return 0;
}