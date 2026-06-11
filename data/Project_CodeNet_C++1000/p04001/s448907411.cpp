#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main () {

    string s;
    cin >> s;

    long long sum =0;
    int n =s.size();

    rep(i,1 << n -1){
        long long t  =s[0] -'0';

        rep(j, n-1){

            if(i & (1 << j)){
                sum += t;
                t = s[j+1] -'0';
            }
            else{
                t *= 10;
                t += s[j+1] - '0';
            }
        }
        sum += t;
    }

    cout << sum << endl;

}
