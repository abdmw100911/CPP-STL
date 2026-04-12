/*
Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.
Example 1:
Input:
 N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
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
    vector<int> arr = {5,7,7,8,8,8,8,8,8,10};
    int target = 8;
    vector<int> res = findFirstAndLast(arr,target);

    //COUNT OF OCCURENCES
    int occurences = (res[1]-res[0]) + 1;
    cout<<"count of occurence of "<<target<<" is "<<occurences<<endl;
    return 0;
}