#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> arr;
  int n;
  cout<<"enter the size of the array"<<endl;
  cin>>n;
  cout<<"enter the elements of the array"<<endl;
  int x;
  for(int i=0;i<n;i++){
    cin>>x;
    arr.push_back(x);
  }

  //reversing the array
  int l = 0;
  int r = n-1;
  int temp;
  while(l<(n/2)){
    temp = arr[l];
    arr[l]=arr[r];
    arr[r] = temp;
    l++;
    r--;
  }
  
  //printing the reversed array
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}