#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> nums(N);
    for (int i=0; i<N; i++){
        cin >> nums.at(i);
    }
    sort(nums.begin(), nums.end());
    bool judge=true;
    if (nums.size()%2==0){//要素数が偶数だった場合
        for (int i=0; i<N-2; i+=2){
            if (nums.at(0)!=1 || nums.at(i)!=nums.at(i+1) || nums.at(i)+2!=nums.at(i+2)){
                judge=false;
                break;
            }
        }
    } else {//要素数が奇数だったとき
        for (int i=2; i<N; i+=2){
            if (nums.at(0)!=0 || nums.at(i)!=nums.at(i-1) || nums.at(i)-2!=nums.at(i-2)){
                judge=false;
                break;
            }
        }
    }
    //cout << "judge is " << judge << endl;
    if (judge){
        //long long answer=(long long)pow(2, nums.size()/2)%1000000007;
        //cout << (long long)pow(2, nums.size()/2)%1000000007 << endl;
        long long answer=1;
        for (int i=0; i<N/2; i++){
            answer*=2;
            answer%=1000000007;
        }
        cout << answer << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}