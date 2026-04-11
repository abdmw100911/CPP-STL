#include<bits/stdc++.h>
using namespace std;
int findUpperBound(vector<int> arr, int x){
    int low = 0;
    int high = arr.size()-1;
    int mid;
    int ans = arr.size();
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]>x){
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] <= x){
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,3,4};
    int x;
    cout<<"enter the number to find its upperbound"<<endl;
    cin>>x;
    cout<<findUpperBound(arr,x)<<" is the upperbound index of "<<x<<endl;
}