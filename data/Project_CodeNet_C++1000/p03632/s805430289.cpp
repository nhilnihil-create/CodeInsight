#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    vector<int> alice(101,0);
    vector<int> bob(101,0);

    for(int i=a; i<b; i++){
        alice[i]=1;
    }
    for(int i=c; i<d; i++){
        bob[i]=1;
    }

    int sum=0;
    for(int i=0;i<=100;i++){
        if(alice[i]==1 && bob[i]==1){
            sum++;
        }
    }

    cout << sum << endl;
    return 0;
}