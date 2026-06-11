#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int b_4=0, e=0, o=0;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]%4==0){
            b_4++;
        }else if(a[i]%2==0){
            e++;
        }else{
            o++;
        }
    }
    if(o==n){
        puts("No");
        return 0;
    }
    if(e+b_4==n){
        puts("Yes");
        return 0;
    }
    if(2*b_4+1>=n){
        puts("Yes");
        return 0;
    }
    if(n-2*b_4<=e){
        puts("Yes");
        return 0;
    }
    puts("No");
    return 0;
}