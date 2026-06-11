#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
bool check[1000];
int arr[1000];
int main(){
    int diff=0, max=0, maxl=0, y=1, temp=0, minl=INT_MAX;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(check[s[i]]==false){
            check[s[i]]=true;
            diff++;
        }
        arr[s[i]]++;
        if(arr[s[i]]>max){
            max=arr[s[i]];
        }
    }
    if(diff==1){
        cout << maxl << endl;
    }
    else if(diff==s.size()){
        maxl=s.size()/2;
        cout << maxl << endl;
    }
    else{
        for(int i='a'; i<='z'; i++){
                for(int j=0; j<s.size(); j++){
                    if(s[j]!=i){
                        temp++;
                    }
                    else{
                        if(maxl<temp){
                            maxl = temp;
                        }
                        temp=0;
                    }
                }
                if(maxl<temp){
                    maxl=temp;
                }
                minl=min(maxl, minl);
            temp=0;
            maxl=0;
        }
        maxl = s.size()/2;
        cout << min(maxl, minl) << endl;
    }
    return 0;
}