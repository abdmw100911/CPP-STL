/*
lower bound: if x is a given target , lower bound is the "index of the first value >= x"
if no number is >= x , then return a number greater than the last number of the array
*/
#include<bits/stdc++.h>
using namespace std;
int linearApproach(vector<int> arr, int x){
    int n = arr.size();
    int ans = arr[arr.size()-1] + 1;
    for(int i=0;i<n;i++){
        if(arr[i]>=x)
        return arr[i];
    }
    return ans;
}

int binaryApproach(vector<int> arr, int x){
    int low = 0;
    int high = arr.size()-1;
    int mid;
    int ans = arr[arr.size()-1] + 1;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] >= x){
            ans=arr[mid];
            high = mid - 1;
        }
        else if (arr[mid] < x){
            low = mid + 1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1,3,5,7,9};
    int x;
    cout<<"enter the number to find its lowerbound in array"<<endl;
    cin>>x;
    cout<<linearApproach(arr,x)<<" lower bound of linear apprach"<<endl;
    cout<<binaryApproach(arr,x)<<" lower bound of binary approach"<<endl;
    return 0;
}