#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



int main(){
    long long q,h,s,d;
    long long n;
    cin >> q >> h >> s >> d >> n;

    if(n==1){
        //1Lあたりの値段
        q*=4;
        h*=2;
        long long ans = min(q,min(h,s));
        cout << n*ans << endl;
    }else{
        //2Lあたりの値段
        q*=8;
        h*=4;
        s*=2;

        long long ans = min(q,min(h,min(s,d)));
        if(n%2==1){
            if(ans==d){
                long long ans2 = min(q,min(h,s));
                ans2/=2;
                cout << (n/2)*ans + ans2;
            }else{
                ans/=2;
                cout << n*ans << endl;
            }
        }else{
            cout << (n/2)*ans << endl;
        }
    }

}

