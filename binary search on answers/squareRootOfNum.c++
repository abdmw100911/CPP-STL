#include<bits/stdc++.h>
using namespace std;
int findSquareRoot(int num){
    //using binary search 
    /*deciding range :
    the minimum possible value will be 1 
    and the maximum possible value will be n/2
    */
   int low = 1;
   int high = num/2;
   int mid;
   int res = 1;
   while(low<=high){
    mid = (low+high)/2;
    if(mid<=num/mid){ //mid * mid will cause overflow , so we use this instead
        res = mid;
        low = mid + 1;
    }
    else{
        high = mid - 1;
    }
   }
   return res;
}
int main(){
    int num = 25;
    cout<<findSquareRoot(num)<<" is the closest square root"<<endl;
    return 0;
}