#include<bits/stdc++.h>
using namespace std;

void incrementByOne(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
      arr[i]++;
    }
  }


int main(){
  vector<int> arr = {1,2,3,4,5};
  incrementByOne(arr);
  for(int i=0 ;i <5 ; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}