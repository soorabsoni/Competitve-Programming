	/*
	Problem Link :- https://codeforces.com/problemset/problem/1360/B
	Contributed by :- Tejas Bir Singh
	Time Complexity  :- O(N * Log(N))
	Space Complexity :- O(1) , input array is not considered as extra space 
	*/

	#include<bits/stdc++.h>
	using namespace std;


	int main(){

		int t=0;
		cin>>t;
		while(t--){

		   int n;
		   cin>>n;

		   vector<int> arr(n);

		   for(int i=0; i<n; i++) {
		   	cin>>arr[i];
		   }

		   int res = INT_MAX;

		   /* inbuilt sort function uses quicksort 
			  so time complexity in average and best case is O(n*Log(n)) and worst case is O(n * n) 
			  where n is number of elements in array	
		   */
		   sort(arr.begin(), arr.end());

		   /* By sorting the array we will get minimum difference between 2 adjacent elements
			  as the ordering doesn't matter 
			  we will find 2 adjacent elements which will be our partition point for both teams 	
		   */
		   for(int i=0; i<n-1;i++){

		   	  // to find the min difference we will keep updating the res to min(res,currDiff)	
		   	  int currDiff = abs(arr[i+1] - arr[i]);
		  	  res = min(res, currDiff);
		   }

		   cout<<res<<"\n";
		}
	}

	/*
	Sample Test Cases:-

		INPUT:- 
			5
			5
			3 1 2 6 4
			6
			2 1 3 2 4 3
			4
			7 9 3 1
			2
			1 1000
			3
			100 150 200


		OUTPUT:-
			1
			0
			2
			999
			50

	*/