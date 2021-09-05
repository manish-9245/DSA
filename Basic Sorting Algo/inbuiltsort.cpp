 #include<iostream>
 #include<algorithm>
using namespace std;
bool compare(int a,int b){
	return a>b;
}
//Time Complexity of the sort algorithm is O(nLogn)
int main(){
	int arr[]={4,5,2,3,9,8};
	int n=sizeof(arr)/sizeof(int);
	//Instead of compare fuction the greater<int>() can also be used
	sort(arr,arr+n,compare);//Sorts in ascending order  //We are passing the function as a parameter to another function
	//reverse(arr,arr+n);//used to reverse
	for(int x: arr){
		cout<<x<<" ";
	}
	return 0;
}
