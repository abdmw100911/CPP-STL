#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& arr) {
        /*
        4 5 6 7 0 1 2
        l     m     h
        */
        int low = 0;
        int high = arr.size() - 1;
        int mid;
        int mini = INT_MAX;

        while(low<=high){
            mid = (low+high)/2;
            //check which part is sorted
            if(arr[low]<=arr[mid]){
                //left part is sorted 
                //take minimum from left sorted part and eliminate it
                mini = min(mini,arr[low]);
                low = mid+1;
            }
            else{
                //right part is sorted 
                //take minimum from right part and eliminate it 
                mini = min(mini, arr[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
int main(){
    vector<int> arr = {4,5,6,7,0,2};
    cout<<findMin(arr)<<" is the minimum in the rotated sorted array"<<endl;
    return 0;
}