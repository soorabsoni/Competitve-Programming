/*
Problem Link:- https://codeforces.com/problemset/problem/1360/A
Time Complexity:- O(1)
Space Complexity:- O(1) 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	// t is the number of test cases
	int t;
	cin>>t;
	while(t--){
		// take the input of sides of rectangle
		int length,breadth;
		cin>>length>>breadth;

		/*
			we need to find the square with minimum area to include 2 rectangles
			we will find the max side of the square required
			by keeping the rectangles horizonatally parallel and 
			vertical parallel
		*/
		int parallelHoriLen = max(2*length,breadth);
		int parallelVertLen = max(2*breadth,length);

		/*
			As we need to find the minimum square area we will take the minimum 
			of both sides
		*/
		cout<<min(parallelHoriLen * parallelHoriLen, parallelVertLen * parallelVertLen);
		cout<<"\n";
		
	}
	return 0;
}

/*
Sample Test cases:-
	INPUT:- 
		8
		3 2
		4 2
		1 1
		3 1
		4 7
		1 3
		7 4
		100 100
	OUTPUT:-
		16
		16
		4
		9
		64
		9
		64
		40000

*/