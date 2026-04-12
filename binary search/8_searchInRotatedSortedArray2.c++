#include<bits/stdc++.h>
using namespace std;
int searchInRotatedSortedArray(vector<int> arr, int target){
    //   3 1 2 3 3 3 3 
    //   l     m     h
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if (arr[low] == arr[mid] && arr[mid] == arr[high]){
            //shrinking the search space from both ends
            low += 1;
            high -= 1;
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
    vector<int> arr = {3,1,2,3,3,3};
    int target = 2;
    cout<<target<<" is at index "<<searchInRotatedSortedArray(arr,target)<<endl;
    return 0;
}