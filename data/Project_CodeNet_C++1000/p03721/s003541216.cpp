#include<iostream>
#include<map>
using namespace std;

int main(){
    long N, K;
    cin >> N >> K;
    map<long, long> List;
    for (int i=0; i<N; i++){
        long a, b;
        cin >> a >> b;
        if (List.find(a) == List.end()){
            List.emplace(a,b);
        }
        else{
            List[a] += b;
        } 
    }
    long order = 0, ans = -1;
    for (auto x : List){
        order += x.second;
        if (order >= K){
            ans = x.first;
            break;
        } 
    }
    cout << ans << endl;;
    return 0;
}