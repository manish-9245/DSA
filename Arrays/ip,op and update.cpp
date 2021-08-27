
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	//create,update and output
	int marks[100]={0};
	int n;
	marks[0]=-1;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>marks[i];
		marks[i]=marks[i]*2;
	}
		for (int i=0;i<=50;i++){
		cout<<marks[i]<<" ,";
	}
	return 0;
}

