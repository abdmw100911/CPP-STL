#include<bits/stdc++.h>
using namespace std;
void explainVector(){
  
  //##defining a vector
  //vector<data type of elements> name(size,element);
  vector<int> v(5,0);

  for(auto it : v){
    cout<<it<<" ";
  }
  cout<<endl;

  //##putting elements inside vector
  v.push_back(1);

  v.emplace_back(2);

  for(auto it : v){
    cout<<it<<" ";
  }
  cout<<endl;

  //vector of pairs
  vector<pair<int,int>> vpair = {{1,2},{3,4},{5,6}};

  //adding through push_back
  vpair.push_back({7,8});

  //adding through emplace_back
  vpair.emplace_back(9,10);

  for(auto it : vpair){
    cout<<it.first<<" "<<it.second<<endl;
  }

  //copying a vector into another 
  vector<int> v1(v);

  for(auto it : v1){
    cout<<it<<" ";
  }
  cout<<endl;
  
 
  //##iterators in vectors
  vector<int> v2 = {1,2,3,4,5};

  vector<int>::iterator it = v2.begin(); //address of first element in the array

  cout<<*it<<endl;
  it++; //next index address
  cout<<*it<<endl;

  //shortcut for defining iterator
  //v.end() gives address on memory one location after the last element
  auto it1 = v2.end()-1;
  cout<<*it1<<endl;

//looping using an iterator
for(auto it=v2.begin(); it != v2.end() ; it++){
  //stors address of values of v2 in (it)
  cout<<*it<<" ";
}
cout<<endl;

for(auto it : v2){
  //stores a copy of values of v2 in (it) 
  cout<<it<<" ";
}
cout<<endl;

//##deletion in vector
//v.erase(start address, end address(not included))

v2.erase(v2.begin());
for(auto it : v2){
  cout<<it<<" ";
}
cout<<endl;

v2.erase(v2.begin(),v2.end()-1);
for(auto it : v2){
  cout<<it<<" ";
}
cout<<endl;

//insertion in vector
//v.insert(address, count, value);
//inserts before the address , not after
vector<int> v3 = {5,1,7,9,3};

v3.insert(v3.begin()+2,6);

for(auto it : v3){
  cout<<it<<" ";
}
cout<<endl;

v3.insert(v3.begin()+3,2,7);
for(auto it : v3){
  cout<<it<<" ";
}
cout<<endl;

//clearing a vector
v3.clear();
for(auto it : v3){
  cout<<it<<" ";
}
cout<<endl;
}
int main(){
  explainVector();
  return 0;
}