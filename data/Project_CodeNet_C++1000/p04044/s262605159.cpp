    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int n;
      cin>>n;
      int len;
      cin>>len;
        string arr[n];
      for(int i=0;i<n;i++){
        cin>>arr[i];
      }
      sort(arr,arr+n);
      string output;
      for(int i=0;i<n;i++){
        output+=arr[i];
      }
      cout<<output;
    }
