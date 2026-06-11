#include<bits/stdc++.h>

using namespace std;

int main(){
    long long a,b,x;
    cin >> a >> b >> x;

    //long long ans = b/x;
    //ans = ans  - (a-1)/x;
    long long A = a/x;
    long long B = b/x;

    long long ans = B - A;
    if(a%x==0){
        ans++;
    }

    cout << ans << endl;

    /*
    long long tmp,tmp_, count=0;
    long long tmp_x=1,tmp_y=1;
    if(10*x<b){
        tmp_ = 10*x;
        tmp_x = b/(10*x);
        //cout << tmp_x << endl;
        tmp_y = b%(10*x);
        //cout << tmp_y << endl;
    }
    else{
        tmp_ = b;
    }
    for(long long i=a; i<=tmp_; i++){
        //cout << i << endl;
        if(i%x==0){
            count++;
        }
    }
    //cout << count << endl;
    count = count * tmp_x;
    for(long long i=1; i<tmp_y; i++){
        if(i%x==0){
            count++;
        }
    }
    cout << count << endl;
    */
    
    return 0;
}