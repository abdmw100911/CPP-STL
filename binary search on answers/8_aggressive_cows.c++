/*
Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.


Example 1

Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

Output: 3

Explanation:

The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.

In no manner can we increase the minimum distance beyond 3.
*/
#include<bits/stdc++.h>
using namespace std;

bool canCowsFit(vector<int> arr, int cows, int minDist){
    int cowsPlaced = 1;
    int lastCowPos = 0;
    int n = arr.size() - 1;

    for(int i=1; i<=n; i++){
        if(arr[i] - arr[lastCowPos] >= minDist){
            cowsPlaced += 1;
            lastCowPos = i;
        }
    }

    if(cowsPlaced < cows){
        return false;
    }else{
        return true;
    }

}
int aggressiveCows(vector<int> arr, int cows){
    //1. sort the array, so that distances are consecutive
    sort(arr.begin(),arr.end());

    //2. define range of minimum distances 
    int n = arr.size() - 1;
    int low = 1;
    int high = arr[n] - arr[0]; //arr[min] - arr[max] , ceil of range

    //3. try the minimum distances
    int possibleAns = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(canCowsFit(arr,cows,mid) == true){
            possibleAns = mid;
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }

    return possibleAns;

}
int main(){
    vector<int> arr = {0,3,4,7,10,9};
    int cows = 4;
    cout<<aggressiveCows(arr,cows)<<" is the maximum of minimum dist between cows";
    return 0;
}