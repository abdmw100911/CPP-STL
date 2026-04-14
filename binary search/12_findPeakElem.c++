/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

*/
#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> arr) {
    int low = 0 ;
    int high = arr.size() - 1;
    int mid;
    
    //handling edge cases 
    //only one element in the array 
    if(arr.size() == 1){
        return 0;
    }
    //first or last element is peak
    else if(arr[low]>arr[low+1]){
        return low;
    }
    else if(arr[high] > arr[high - 1]){
        return high;
    }
    //since we have checked 1st and last element for peak , we can remove them from search space
    low +=1;
    high -=1;

    int left;
    int right;
    while(low<=high){
        mid = (low+high)/2;
        left = mid - 1;
        right = mid + 1;
        if(arr[mid]>arr[left] && arr[mid]>arr[right]){
            //found the peak
            return mid;
        }
        else if(arr[mid]>arr[left]){
            //mid is on left side of peak
            low = mid + 1;
        }
        else{
            //mid is on right side of peak
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    cout<<findPeakElement(arr)<<" is the index of the peak element in the array"<<endl;
    return 0;
}