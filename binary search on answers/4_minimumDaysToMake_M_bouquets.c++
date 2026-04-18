#include<bits/stdc++.h>
using namespace std;
bool bouquetPossible(vector<int> &arr, int day, int m, int k){
    int count = 0;
    int numOfB = 0;
    for(int i=0;i<arr.size();i++){
        if(day>=arr[i]){
            //its a bloom day
            //count flowers that can be plucked on consecutive bloomdays
            count++;
        }
        else{
            //not consecutive bloom day, reset counter
            //consecutive bloom day count/no.of flowers required 
            //this will give number of bouqutes 
            numOfB += count/k;
            count = 0;
        }
    }
    //after the loop , count will have the number of consecutive bloomdays still
    numOfB += count/k;
    if(numOfB >= m){
        return true;
    }
    else{
        return false;
    }
}
int minDays(vector<int>& bloomDay, int m, int k) {
    //to find range of binary search we need to get min and max element
    //from the array
    int mini = *min_element(bloomDay.begin(),bloomDay.end());
    int maxi = *max_element(bloomDay.begin(),bloomDay.end());
    int low = mini;
    int high = maxi;
    int mid;
    int res = -1;
    
    while(low<=high){
        mid = (low+high)/2;
        if(bouquetPossible(bloomDay,mid,m,k)){
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
    vector<int> bloomDay = {7,7,7,7,13,11,12,7};
    int m = 2;
    int k = 3;
    cout<<minDays(bloomDay,m,k)<<" is the minimum days to make "<<m<<" bouquets"<<endl;
    return 0;
}