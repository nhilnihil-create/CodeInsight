#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(){

    int size,a,b,min=9999999,max=-1,ans = 0;
    cin >> size;
    map<int,int> dicts;
    for(int i=0;i<size;i++){
        cin >> a >> b;
        if(a<min){
            min = a;
        }
        if(a>max){
            max = a;
        }
        dicts[a] = b;
    }
    ans += dicts[max]+1+(max-min) +(min-1);
    cout << ans;


}