/*
USING THE LOWERBOUND FUNCTION

vector<int> arr = {1,3,5,7,9};

auto it = lower_bound(arr.begin(), arr.end(), 6);
cout << *it;                        // 7 (value)
cout << it - arr.begin();           // 3 (index)
*/
#include<bits/stdc++.h>
using namespace std;

int searchInsertPosition(vector<int> arr , int x){
    //search insert position is basically finding the lowerbound

    auto it = lower_bound(arr.begin(),arr.end(),x);

    return (it - arr.begin());
}
int main(){
    vector<int> arr = {1,3,5,6};
    int x;
    cout<<"enter number to find its insert position"<<endl;
    cin>>x;
    cout<<searchInsertPosition(arr,x)<<endl;
    return 0;
}