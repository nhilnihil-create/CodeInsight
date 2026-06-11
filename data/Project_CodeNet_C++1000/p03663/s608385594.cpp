#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define int long long int
using namespace std;
int n;
char mock(int x){
    if((to_string(x) <= to_string(n) && x <= n) ||
            (to_string(x) > to_string(n) && x  > n))return 'Y';
    return 'N';
}
bool query(int x){
    while(x < 1e10)x *= 10;
    cout << "? " << x << endl;
    //char s = mock(x);
    string s;cin >> s;
    if(s == "Y")return true;
    else return false;
}
bool query1(int x){
    cout << "? " << x << endl;
    string s;cin >> s;
    //char s = mock(x);
    if(s == "Y")return true;
    else return false;

}
void ans(int x){
    cout << "! " << x << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cin >> n;
    int prev = 0;
    for(int dig = 1; dig <= 10; dig++){
        int s = 0, e = 9;
        int temp = -1;
        while(s <= e){
            int mid = (s +e) >> 1;
            int x = prev*10 + mid;
            if(query1(x)){
                temp = mid; 
                s = mid+1;
            }else{
                e = mid-1;
            } 
        }
        if(temp == 9){//might be last digit
            // 1. check if the last digit is 9
            // 2. if it is not nine then this is the last digit
            // 3. if it is nine then check with 80 whether this is the last digit
            bool last = false;
            if(!query(prev*10 + 8)){
               //last digit is nine  
               if(!query1((prev*100 + 80)))last= true;
            }else{
                last = true;
            }
            if(!last)goto leave;
            FOR(i, 9+1){
                if(prev == 0 && i == 0)continue;
                if(query(prev*10 + i)){
                    prev= prev*10 + i;
                    break;
                }
            }
            break;
        }
leave:
        prev = (prev)*10 + temp;
    }
    ans(prev);
}


