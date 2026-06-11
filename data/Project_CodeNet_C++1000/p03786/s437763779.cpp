#include <iostream> 
#include <algorithm>
using namespace std;
int main(){
    bool check = true;
    int n;
    int arr[100005];
    long long color=1, yeah[100005];
    cin >>n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    yeah[0]=0;
    sort(arr+1, arr+1+n);
    for(int i=1; i<=n; i++){
       yeah[i]=arr[i]+yeah[i-1];
    }
    for(int i=n-1; i>=1; i--){
        if(yeah[i]*2>=arr[i+1] && check == true){
            color++;
        }
        else{
            check=false;
        }
    }
    cout << color << endl;
    return 0;
}