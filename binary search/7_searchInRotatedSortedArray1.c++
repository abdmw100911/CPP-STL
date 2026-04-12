/*
Problem Statement: Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.

Examples
Input:nums = [4, 5, 6, 7, 0, 1, 2], k = 0
Output :4
Explanation : Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3
Output :-1
Explanation :Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.
*/
#include<bits/stdc++.h>
using namespace std;
int searchInRotatedSortedArray(vector<int> arr, int target){
    //4 5 6 7 0 1 2
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[low]<=arr[mid]){
            //if left part is sorted
            if(target >= arr[low] && target <= arr[mid]){
                //target is within range of left part 
                //continue search in left part
                high = mid - 1;
            }
            else{
                //target is not in the range of left sorted part
                //continue search in right part 
                low = mid + 1;
            }
        }
        else if(arr[mid] <= arr[high]){
            //if right part is sorted
            if(target >= arr[mid] && target <= arr[high]){
                //target is in the range of right sorted part 
                //continue search in right sorted part
                low = mid + 1;
            }
            else{
                //element is not in range of right sorted part
                //continue search in left sorted part 
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;
    cout<<"element is present at index "<<searchInRotatedSortedArray(arr,target) <<endl;
    return 0;
}