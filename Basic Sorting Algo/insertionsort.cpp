//Time Complexity O(n^2)
#include <iostream>
using namespace std;
void insertion_sort(int a[],int n){
	for(int i=1; i<=n-1; i++){

		int current = a[i];

		int prev = i - 1; 
		//to find node for insertion
		while(prev>=0 and a[prev] > current){
			a[prev + 1] = a[prev];
			prev = prev - 1;
		}

		a[prev+1] = current; 
	}

}
int main() {
	// your code goes here
	int a[]={1,-5,4,3};
	int n=sizeof(a)/sizeof(int);
	insertion_sort(a,n);
	for(auto x: a)
	cout<<x<<",";
	return 0;
}

