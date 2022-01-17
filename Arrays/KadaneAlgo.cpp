//Time Complexity O(n)
#include<iostream>
using namespace std;
int maximum_subarray_sum(int arr[],int n){
	int cs = 0;
	int largest = 0;
	for(int i=0;i<n;i++){
		cs = cs + arr[i];
		if(cs < 0){
			cs = 0;
		}
		largest = max(largest, cs);
	}
	return largest;
}
int main(){
	//Array Containing
	int arr[] = {3,4,5,-2,6};
	int n = sizeof(arr)/sizeof(int);
	cout<< maximum_subarray_sum(arr,n) <<endl;
	return 0;
}