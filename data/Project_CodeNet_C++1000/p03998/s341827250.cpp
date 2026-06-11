#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    string s1,s2,s3; cin >> s1 >> s2 >> s3;
    vector<int> index(3, 0);
    int s = 0;
    while(1){
        if(index[0] > s1.length()){
            cout << 'A' << endl;
            return 0;
        }else if(index[1] > s2.length()){
            cout << 'B' << endl;
            return 0;
        }else if(index[2] > s3.length()){
            cout << 'C' << endl;
            return 0;
        }
        if(s == 0){
            s = s1[index[0]] -'a';
            index[0]++;
        }else if(s == 1){
            s= s2[index[1]] - 'a';
            index[1]++;
        }else{
            s = s3[index[2]] - 'a';
            index[2]++;
        }
        
    }
}