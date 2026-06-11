 #include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    bool flag = true;
    int arr[26] = {};
    for(int i=0;i<str.length();i++){
    	arr[str[i]-97]++;
    }
    for(int i=0;i<26;i++){
    	if(arr[i]%2==1){
    		flag = false;
            break;
    	}
    }
    if(flag){
    	cout << "Yes" << endl;
    }
    else{
    	cout << "No" << endl;
    }
	return 0;
}