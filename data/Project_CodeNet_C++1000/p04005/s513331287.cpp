#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<long long> vec(3);
    cin >> vec[0] >> vec[1] >> vec[2];
    long long red,blue;
    long long h,w;
    long long ans;
    if(vec[0]%2==0 || vec[1]%2==0 || vec[2]%2==0){
        cout << "0" << endl;
    }else{
        sort(vec.begin(),vec.end());
        h = vec[2]/2;
        w = vec[2]-h;
        red = h*vec[1]*vec[0];
        blue = w*vec[1]*vec[0];
        ans = abs(red-blue);
        cout << ans << endl;
    }
}

