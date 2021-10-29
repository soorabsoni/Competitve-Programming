#include<bits/stdc++.h>
using namespace std;

int main() {
    string str = "hardassadrah";
    bool flag = true;

    int n = str.size();
    for (int i = 0; i < n/2; i++) {
	if (s[i] != s[n-i-1]) {
	    flag = false;
	    break;
	}
    }

    if (flag) cout << "Pallindrome: YES" << endl;
    else cout << "Not a Pallindrome" << endl;

    return 0;
}
