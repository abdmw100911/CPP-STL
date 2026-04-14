/*
    Find out how many times the array has been rotated
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.
Input : arr = [4,5,6,7,0,1,2,3]
Result: 4
Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

Input : arr = [3,4,5,1,2]
Output : 3
Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.
*/
#include<bits/stdc++.h>
using namespace std;
int numberOfTimesArrayRotated(vector<int> arr){
    int low = 0;
    int high = arr.size()-1;
    int mid;
    int miniIndex;
    int mini = INT_MAX;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[low]<=arr[mid]){
            //left part is sorted 
            if(arr[low]<mini){
                mini = arr[low];
                miniIndex = low;
            }
            low = mid+1;
        }
        else{
            //right part is sorted
            if(arr[mid]<mini){
                mini = arr[mid];
                miniIndex = mid;
            }
            high = mid - 1;
        }
    }
    //minimum element is found
    //get index of the minimum element
    //this extra step was unnecessary, we can track minimum index in the while loop itself
    /*
    auto it = find(arr.begin(),arr.end(),mini);
    miniIndex = it - arr.begin();
    return miniIndex;
    */
   return miniIndex;
}
int main(){
    vector<int> arr = {4,5,6,7,8,0,1,2};
    cout<<numberOfTimesArrayRotated(arr)<<" is the number of times array has been rotated"<<endl;
    return 0;
}