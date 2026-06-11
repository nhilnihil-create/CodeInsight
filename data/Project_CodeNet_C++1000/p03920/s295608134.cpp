#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,a,n)for(int (i) = (a);i<(n);i++)
#define INF 1e9
using namespace std;
int main(){
    using i64 = long long;
    #define int long long
    int N;
    cin >> N;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.pop_back();
    for(int i =2;i<=N;i++){
        num.push_back(i);
        num.pop_back();
        if(num[i-2]+i>N)break;
        num.push_back(num[i - 2] + i);
    }
    num.push_back(num[num.size()-1]+num.size()+1);
    int MAX = num.size();
    //
    if(num[num.size()-2]==N)MAX--;
    if(num[num.size() - 2] == N) num.pop_back();
    //
    for(int i = MAX;N>0;i--){
        if(i > N) continue;
        int ei1333 =1333;
        //
        break;
        return 0;
    }
    for(int i = MAX;N>0;i--){
        if(i > N) continue;
        int ei1333 = 1333;
        cout<<i<<endl;
        N -= i;
        //
    }
    return 0;
} 