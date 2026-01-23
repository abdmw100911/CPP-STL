#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> arr = {5,1,7,9,3};

  //add elements 
  arr.push_back(100);
  for(auto it : arr){
    cout<<it<<" ";
  }
  cout<<endl;

  //remove elements 
  arr.pop_back();
  for(auto it : arr){
    cout<<it<<" ";
  }
  cout<<endl;
  //sorting ascending
  sort(arr.begin(),arr.end());
  for(auto it : arr){
    cout<<it<<" ";
  }
  cout<<endl;

  //sorting descending
  sort(arr.begin(),arr.end(),greater<int>());
  for(auto it : arr){
    cout<<it<<" ";
  }
  cout<<endl;
  return 0;
}