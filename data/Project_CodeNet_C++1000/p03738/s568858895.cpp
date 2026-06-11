#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<string>
#include<queue>

using namespace std;

#define ll long long
typedef pair<ll, ll> P;

int main(){
    string A,B;
    cin >> A >> B;
    int dif = 'A' - 'a';
    // cout << dif;
    if(A.size() == B.size()){
        for(int i=0; i<A.size(); i++){
            if(A[i] > B[i]){
                cout << "GREATER" << endl;
                return 0;
            }else if(A[i] < B[i]){
                cout << "LESS" << endl;
                return 0;
             } 
            if(i == A.size()-1 && A[i] == B[i]) cout << "EQUAL" << endl;
        }
    }else{
        if(A.size() > B.size()){
            cout << "GREATER" << endl;
        }else{
            cout << "LESS" << endl;
        }
    }
}