#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N,0);
    for(int i=0;i<N;i++){
        cin>>vec.at(i);
    }
    //今の光がどれかを保存する関数を用意
    int light=1,count=0;
    for(int i=0;i<N;i++){
    light = vec.at(light - 1);
     count++;
     if(light == 2){
     cout << count << endl;
     return 0;
     }
    }
    cout <<-1 <<endl;
}