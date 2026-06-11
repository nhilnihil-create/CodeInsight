#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> decrease(n+1,0);
    vector<int> num(n+1);

    vector<int> sumNum(n+1);


    for(int i=0;i<n;++i){
         cin >> v[i];
    }


    if(n>1){
        for(int i = 2; i < n; ++i){
            int minus = (v[i-1])/2;
            if((v[i-1]) % 2 == 1) minus ++;
            minus = i - minus;


            decrease[i] = max(decrease[i-1],minus);
        }
    }


    for(int i=0;i<n;++i){
//        cout << decrease[i]<<" ";
        num[decrease[i]]++;
    }

    sumNum[0] = num[0];

    for(int i = 1;i<=n;++i){
        sumNum[i] = num[i]+sumNum[i-1];
    }
//    cout << endl;
//    for(int i=0;i<n;++i){
//        cout <<i<<" "<< sumNum[i]<<endl;
//    }


    long long ans = num[0];
    for(int i=1;i<n;++i){
//        if(num[i] == 0) break;
        ans *= (sumNum[i] - i);
        ans %=1000000007;
    }

    cout << ans;
}
