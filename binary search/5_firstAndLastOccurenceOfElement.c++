/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> findFirstAndLast(vector<int> arr, int target){
    //first position is the lower bound of the target
    //last position is one index behind the upper bound of target 
    
    auto lowerBound = lower_bound(arr.begin(),arr.end(),target);
    int firstPositionIndex = lowerBound - arr.begin();

    //edge case
    //1.lowerbound element is not equal to target
    //2.lowerbound doesnot exist in the array 
    //in both cases first occurence of the element is not found in the array,thus element doesnot exist in the array
    if(arr[firstPositionIndex] != target || lowerBound == arr.end()){
        return {-1,-1};
    }

    auto upperBound = upper_bound(arr.begin(),arr.end(),target);
    int lastPositionIndex = (upperBound - arr.begin()) - 1;

    return {firstPositionIndex,lastPositionIndex};
}
int main(){
    vector<int> arr = {5,7,7,8,8,10};
    int target = 6;
    vector<int> res = findFirstAndLast(arr,target);

    for(auto num : res){
        cout<<num<<" ";
    }
    return 0;
}