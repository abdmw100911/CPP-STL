#include<bits/stdc++.h>
using namespace std;
void explainSets(){
  //in set everything happens in logn timecomplexity
  //set stores unique elements in sorted manner
  set<int> st = {1,2,3,0};
  for(auto it : st){
    cout<<it<<" ";
  }
  cout<<endl;
  st.insert(1); //wont be inserted
  st.emplace(4);
  st.insert(5);

  for(auto it : st){
    cout<<it<<" ";
  }
  cout<<endl;

  //begin(), end(), empty(), size(), same 

  //finding element in set 
  auto it = st.find(5);

  //if it == st.end(), it means element is not in set
  if(it != st.end()){
    cout<<"found"<<endl;
  }
  else
  cout<<"not found"<<endl;

  //removing element from set
  st.erase(5);
  for(auto it : st){
    cout<<it<<" ";
  }
  cout<<endl;

  //count():used to find if element is present in set or not 
  int cnt = st.count(5);
  //set stores unique elements
  //if element is there , cnt =1 , else cnt = 0

  cout<<cnt<<endl; //0

  cnt = st.count(1);
  cout<<cnt<<endl; //1

  //removing element through address 
  auto it1 = st.find(0);
  st.erase(it1);
  cnt = st.count(0); //0
  cout<<cnt<<endl;

  //removing specific portion 
  it = st.find(1);
  it1 = st.find(3);
  st.erase(it,it1);
  for(auto it : st){
    cout<<it<<" ";
  }
  cout<<endl;

  //multiset:stores element in sorted order , allows duplicates
  multiset<int> mst = {1,1,2,3,4,4};
  for(auto it : mst){
    cout<<it<<" ";
  }
  cout<<endl;
}
int main(){

  explainSets();
  return 0;
}