/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/
#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& arr) {
    int low = 0; 
    int high = arr.size() - 1;
    int mid;
    int left;
    int right;
    //edge cases
    //when mid reaches last or first index , then it is definitely the 
    //the single element
    /*
    // if mid is at start, no left neighbor, so it must be single
    {1, 1, 2, 2, 3}  →  single is at index 4 (last)

    // if mid is at end, no right neighbor, so it must be single  
    {1, 2, 2, 3, 3}  →  single is at index 0 (first)
    */

    while(low<=high){
        mid = (low+high)/2;

        //handling edge case
        if(mid == 0 || mid == (arr.size() - 1)){
        return arr[mid];
        }
        
        left = mid - 1;
        right = mid + 1;
        //checking left of mid for same element
        if(arr[mid] == arr[left]){
            //same elem on left of mid
            if(left%2 == 0){
                //left even , right(mid) odd
                //mid is on left side of single elem 
                //eliminate left part 
                low = mid + 1;
            }
            else{
                //left odd , right(mid) even
                //mid is on right side of single elem
                //eliminate right part
                high = mid - 1;
            }
        }
        else if (arr[mid] == arr[right]){
            //same elem on right of mid
            if(right%2 == 0){
                //left(mid) odd, right even
                //element on right side of single elem
                //eliminate right part
                high = mid - 1;
            }
            else{
                //left(mid) even , right odd
                //element on left side of single elem
                //eliminiate left part
                low = mid + 1;
            }
        }
        else{
            //same elem is not on left nor on right of mid 
            //thus arr[mid] is the single element
            return arr[mid];
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,1,2,2,3,4,4};
    cout<<singleNonDuplicate(arr)<<" is the single element in the array"<<endl;
    return 0;
}