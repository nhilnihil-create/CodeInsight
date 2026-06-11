#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    vector<int> key(n,0);
    int push = 1;
    int count = 0;
    while(1){
        if(push == 2){
            break;
        }else if(key.at(push-1) == 1){
            count = -1;
            break;
        }
        count++;
        key.at(push-1) = 1;
        push = a.at(push-1);
        //cout << "push=" << push << endl;
    }
    cout << count << endl;
    return 0;
}