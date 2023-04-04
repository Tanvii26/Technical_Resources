#include <bits/stdc++.h>
using namespace std;


int knapsackRecursive(vector<int>wt, vector<int>val,int capacity, int n){

    if(capacity == 0 || n==0){
        return 0;
    }
    if(wt[n-1]<=capacity){
        int include = val[n-1] + knapsackRecursive(wt,val,capacity-wt[n-1],n-1);
        int notIncluded = knapsackRecursive(wt,val,capacity,n-1);
        return max(include,notIncluded);

    }

    else if(capacity>wt[n-1]){
        return knapsackRecursive(wt,val,capacity,n-1);
    }
}
int knapsackMemoized(vector<int>wt, vector<int>val,vector<vector<int>>&dp, int capacity, int n){

    if(capacity == 0 || n==0){
        return 0;
    }
    if(dp[n][capacity] != -1){
        return dp[n][capacity];
    }
    if(wt[n-1]<=capacity){
        int include = val[n-1] + knapsackMemoized(wt,val,dp,capacity-wt[n-1],n-1);
        int notIncluded = knapsackMemoized(wt,val,dp,capacity,n-1);
        return dp[n][capacity] = max(include,notIncluded);

    }

    else if(capacity>wt[n-1]){
        return dp[n][capacity] = knapsackMemoized(wt,val,dp,capacity,n-1);
    }
}
int knapsackTabulation(vector<int>wt, vector<int>val, vector<vector<int>> &dp,int capacity, int n){
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    for(int j=0;j<=capacity;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], (val[i-1] + dp[ i-1 ][ j-wt[i-1] ]));
            }
            else
            dp[i][j]= dp[i-1][j];
        }
    }
    return dp[n][capacity];
}
void subsetSum(vector<int> arr, vector<vector<bool>> &dp, int sum, int n){
    for(int j=0;j<=sum;j++){
        dp[0][j] = false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else
            dp[i][j] = dp[i-1][j];
        }
    }

}
bool equalSumPartition(vector<int> arr, vector<vector<bool>> &dp, int n){
    int tot=0;
    for(int i=0;i<n;i++){
        tot += arr[i];
    }

    // s1 = s2 & s1+s2 = tot  => 2s1 = tot, s1=tot/2
    if(tot%2 !=0) return false;

    else{
    subsetSum(arr,dp,tot/2,n);
    return dp[n][tot/2];
    }
}
int subsetCount(vector<int> arr, vector<vector<int>> &dp, int sum, int n){
    for(int j=0;j<=sum;j++){
        dp[0][j] = 0;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int minSubsetDiff(vector<int> arr, int n){
    int tot=0;
    for(int i=0;i<n;i++){
        tot += arr[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(tot+1, -1));
    // s1, s2;  s2=tot-s1;  s2-s1 = tot-s1-s1; => minimize(tot-2*s1)
    subsetSum(arr,dp,tot/2,n); 
    for(int i=tot/2;i>=0;i--){
        if(dp[n][i] == true){
            return (tot-(2*i));
        }
    }
    
}
int subsetCountWithDiff(vector<int> arr, int diff, int n){
    int tot=0;
    for(int i=0;i<n;i++){
        tot += arr[i];
    }
    // s1-s2 = diff but s1+s2 = tot  => 2s1 = diff+tot
    // if s1 sum possible then given diff is possible
    int s1 =(tot+diff)/2;
    vector<vector<int>> dp(n+1,vector<int>(s1+1, -1));
    
}
int main(){

    vector<int> arr;
    int n,sum;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter sum: ";
    cin>>sum;
    
    cout<<"Enter list of items: ";
    int inp;
    for(int i=0;i<n;i++){
        cin>>inp;
        arr.push_back(inp);
    }
    cout<<minSubsetDiff(arr,n);
    return 0;
}