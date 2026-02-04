#include<bits/stdc++.h>
using namespace std;
int findMissingNumber(vector<int> arr){
        //numbers are present from 0 to n 
        //find the size of the array
        // find the expected sum from 1 to n = n*n+1/2
        //find the sum of the array
        //the difference between the expected sum and sum of array is the missing number
        int sum = 0;
        int expectedSum;
        int n = arr.size();
        
        expectedSum = (n*(n+1))/2;
        for(auto it : arr){
            sum = sum + it;
        }
       
        return expectedSum - sum;
}
int main(){
    vector<int> arr = {1,2,3};
    cout<<"Missing number "<<findMissingNumber(arr);
    return 0;
}