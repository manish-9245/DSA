#include<iostream>
using namespace std;
	
//Time Complexity Log(base 2)(n)
//The array needs to be sorted monotonically(ascending,descending or lexically)
int binary_search(int arr[],int n,int key){
	int s = 0;
	int e = n - 1;
	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid] == key){
			return mid;
		}
		else if(arr[mid] > key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return -1;
}
int main(){
	int arr[] = {10,20,30,40,45,60,70,89};
	int n = sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	int index = binary_search(arr,n,key);
	if(index!=-1){
		cout<<key <<" is present at index "<< index <<endl;
	}
	else{
		cout<<key <<" is NOT Found!" <<endl;
	}
	return 0;
}
