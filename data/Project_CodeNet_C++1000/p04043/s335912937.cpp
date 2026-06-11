 #include <bits/stdc++.h>
using namespace std;

int main(){
    int x=0;
    int fc=0,sc=0;
    for(int i=0;i<3;i++){
    	cin >> x;
    	if(x==5){
    		fc++;
    	}
        else if(x==7){
        	sc++;
        }
    }
    //cout << fc << " " << sc;
    if(fc==2&&sc==1){
    	cout << "YES" << endl;
    }
    else{
    	cout << "NO" << endl;
    }
	return 0;
}