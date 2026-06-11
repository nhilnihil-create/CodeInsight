#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> rest(M,0);
    vector<int> pair_(M,0);
    vector<int> stock(100001,0);
    for(int i=0; i<N; i++){
        int x;
        cin >> x;

        pair_[x%M]+=stock[x];
        stock[x]^=1;
        rest[x%M]++;
    }

    int ans=0;
    ans+=rest[0]/2;
    for(int i=1; i<M-i; i++){
        ans+=min(rest[i], rest[M-i]);
        if(rest[i]>rest[M-i]){
            ans+=min((rest[i]-rest[M-i])/2, pair_[i]);
        }else{
            ans+=min((rest[M-i]-rest[i])/2, pair_[M-i]);
        }
        //cout << i << ' ' << ans << endl;
    }
    if(M%2==0){
        ans+=rest[M/2]/2;
    }

    cout << ans << endl;
    //cout_vec(rest);
}