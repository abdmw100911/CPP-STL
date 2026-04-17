#include<bits/stdc++.h>
using namespace std;
long long findRequiredTime(vector<int> piles, int eatingSpeed){
    long long timeRequired = 0;
    for(int i = 0;i<piles.size();i++){
        timeRequired += (((piles[i]+eatingSpeed)-1)/eatingSpeed);
    }
    return timeRequired;
}
int minEatingSpeed(vector<int> piles, int h){
    //1st we have to find max element to define ceil of our search space 
    int maxi = INT_MIN;
    for(int i=0;i<piles.size();i++){
        maxi = max(maxi,piles[i]);
    }
    
    int low = 1;
    int high = maxi;
    int mid; 
    int possibleAns = maxi; //maximum eating speed is the initial possible answer
    long long timeRequired;
    while(low <= high){
        mid = (low+high)/2;
        timeRequired = findRequiredTime(piles, mid);
        if(timeRequired<=h){
            possibleAns = min(possibleAns, mid);
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return possibleAns;
}
int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<minEatingSpeed(piles,h)<<" is the minimum eating speed to devour all bananas within "<<h<<endl;
    return 0;
}