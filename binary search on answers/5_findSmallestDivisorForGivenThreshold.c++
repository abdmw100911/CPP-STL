#include<bits/stdc++.h>
using namespace std;

bool checkDivision(vector<int> &arr,int divisor, int threshold){
    int sumOfDivision = 0;
    for(int i = 0; i<arr.size(); i++){
        sumOfDivision += ((arr[i]+divisor-1)/divisor);
        //ceil value of division
    }
    if(sumOfDivision<=threshold){
        return true;
    }
    else{
        return false;
    }
}
int smallestDivisor(vector<int>& arr, int threshold) {
    int low = 1;
    int high = *max_element(arr.begin(),arr.end());
    int mid;
    int res = -1;
    while(low<=high){
        mid = (low+high)/2;
        if(checkDivision(arr,mid,threshold)){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}
int main(){
    vector<int> arr = {1,2,5,9};
    int threshold = 6;
    cout<<smallestDivisor(arr,threshold)<<" is the smallest divisor for given threshold "<<threshold<<endl;
    return 0;
}