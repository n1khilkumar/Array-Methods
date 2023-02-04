#include<iostream>
#include<time.h>
using namespace std;

struct array
{
	int *A;
	int size;
	int length;
};

void swap(int *num1,int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void insertRandom(struct array *arr,int lim)
{
	srand(time(0));
	for(int i=0;i<arr->length;i++)
	{
		arr->A[i] = rand()%(lim+1); 
	}
}

void insertManually(struct array *arr)
{
	cout<<endl;
	for(int i=0;i<arr->length;i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>arr->A[i];
	}
}

void display(struct array arr)
{
	cout<<"\nElements in the array are: ";
	for(int i=0;i<arr.length;i++)
	{
		cout<<arr.A[i]<<" ";
	}
}

void append(struct array *arr,int x)
{
	if(arr->length<arr->size)
	{
		arr->A[arr->length++] = x;
		cout<<"\nElement added at index: "<<arr->length-1;
	}
	else cout<<"\nArray is full, can't add more elements.";
}

void insert(struct array *arr,int ind,int x)
{														
	if(ind>=0&&ind<=arr->length)
	{
		for(int i=arr->length-1;i>=ind;i--)            
		{								
			arr->A[i+1] = arr->A[i];
		}
		arr->A[ind] = x;
		arr->length++;
		cout<<"\nElement added";
	}
	else cout<<"\nCan't insert at this index.";
}

int Delete(struct array *arr,int ind)
{
	int del = -1;
	if(ind>=0&&ind<=arr->length)
	{
		del = arr->A[ind];
		for(int i=ind;i<arr->length-1;i++)
		{
			arr->A[i] = arr->A[i+1];
		}
		arr->length--;
	}
	return del;
}

int linearSearch(struct array arr,int key)
{
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i] == key) return i;
	}
	return -1;
}

int linearSearchTransposition(struct array *arr,int key)
{
	for(int i=0;i<arr->length;i++)
	{
		if(arr->A[i] == key)
		{
			if(i>0) swap(&arr->A[i],&arr->A[i-1]);
			return i;
		}
	}
	return -1;
}

int linearSearchMoveToFront(struct array *arr,int key)
{
	for(int i=0;i<arr->length;i++)
	{
		if(arr->A[i] == key)
		{
			if(i!=0) swap(&arr->A[i],&arr->A[0]);
			return i;
		}
	}
	return -1;
}

int binarySearchIterative(struct array arr,int key)
{
	int low = 0, high = arr.length-1,mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(arr.A[mid] == key) return mid;
		else if(arr.A[mid] < key) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int binarySearchRecursive(int A[],int key,int low,int high)
{
	if(low<=high)
	{
		int mid = low + (high-low)/2;
		if(A[mid] == key) return mid;
		else if(A[mid]>key) return binarySearchRecursive(A,key,low,mid-1);
		else return binarySearchRecursive(A,key,mid+1,high);
	}
	return -1;
}

void merging(int A[],int low,int mid,int high)
{
	int B[high+1],i=low,j=mid+1,k=low;	
	while(i<=mid&&j<=high)				
	{
		if(A[i]<A[j]) B[k++] = A[i++];
		else B[k++] = A[j++];
	}
	while(i<=mid) B[k++] = A[i++];		
	while(j<=high) B[k++] = A[j++];
	for(i=low;i<=high;i++) A[i] = B[i];	
}

void mergeSort(int A[],int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;			
		mergeSort(A,low,mid);
		mergeSort(A,mid+1,high);
		merging(A,low,mid,high);
	}
}

void get(struct array arr,int ind)
{
	if(ind>=0 && ind<arr.length) cout<<arr.A[ind];
	else cout<<"\nInvalid Index!";
}

void set(struct array *arr,int ind,int x)
{
	if(ind>=0 && ind<arr->length)
	{
		arr->A[ind] = x;
		cout<<"\nElement Set!";
	} 
	else cout<<"\nInvalid Index!";
}

int max(struct array arr)
{
	int maximum = arr.A[0];
	for(int i=1;i<arr.length;i++)
	{
		if(arr.A[i]>maximum) maximum = arr.A[i];
	}
	return maximum;
}

int min(struct array arr)
{
	int minimum = arr.A[0];
	for(int i=1;i<arr.length;i++)
	{
		if(arr.A[i]<minimum) minimum = arr.A[i];
	}
	return minimum;
}

long long int sum(struct array arr)
{
	long long int sum = 0;
	for(int i=0;i<arr.length;i++) sum = sum + arr.A[i];
	return sum;
}

long double avg(struct array arr)
{
	long long int summation = sum(arr);
	long double average = double(summation)/double(arr.length);
	return average;
}

void reverse(struct array *arr)
{
	for(int i=0,j=arr->length-1 ; i<j; i++,j--)
	{
		swap(&arr->A[i],&arr->A[j]);
	}
}

void reorder(struct array *arr,int value)
{
	int i = 0,j = arr->length-1;
	while(i<j)
	{
		while(arr->A[i]<=value) i++;
		while(arr->A[j]>value) j--;
		if(i<j) swap(&arr->A[i++],&arr->A[j--]);
	}
}

void leftShift(struct array *arr)
{
	for(int i=0;i<arr->length-1;i++)
	{
		arr->A[i] = arr->A[i+1];
	}
	arr->A[arr->length-1] = 0;
}

void rightShift(struct array *arr)   
{									
	for(int i=arr->length-1;i>0;i--)
	{
		arr->A[i] = arr->A[i-1];
	}
	arr->A[0] = 0;
}

void leftRotate(struct array *arr)
{
	int temp = arr->A[0];
	for(int i=0;i<arr->length-1;i++)
	{
		arr->A[i] = arr->A[i+1];
	}
	arr->A[arr->length-1] = temp;
}

void rightRotate(struct array *arr)
{
	int temp = arr->A[arr->length-1];
	for(int i=arr->length-1;i>0;i--)
	{
		arr->A[i] = arr->A[i-1];
	}
	arr->A[0] = temp;
}

void insertInSortedArray(struct array *arr,int x)
{
	if(arr->length<arr->size) //1234678   //5
	{
		int i = arr->length-1;
		while(arr->A[i]>x)
		{
			arr->A[i+1] = arr->A[i--];
		}
		arr->A[i+1] = x;
		cout<<"\nValue inserted.";
		arr->length++;
	}
	else cout<<"\nArray at max size can't insert more elements.";
}

bool isSorted(struct array arr)
{
	for(int i=0;i<arr.length-1;i++)
	{
		if(arr.A[i]>arr.A[i+1]) return false;
	}
	return true;
}

int main()
{
	int userIn,lim,x,ind,sort = 0;
	long long int summation;
	long double average;
	struct array arr;
	cout<<"ARRAY MENU DRIVEN PROGRAM"<<endl<<endl;
	cout<<"\nEnter the size of the array: ";
	cin>>arr.size;
	arr.A = new int[arr.size];
	cout<<"Enter the number of elements you want to insert: ";
	cin>>arr.length;
	do
	{
		cout<<"\nPress: "<<endl;
		cout<<"1 to Manually insert elements."<<endl;
		cout<<"2 to Randomly insert elements."<<endl;
		cin>>userIn;
	}while(userIn!=1&&userIn!=2);
	if(userIn == 1) insertManually(&arr);
	else
	{
		cout<<"\nEnter the maximum limit you want for an element: ";
		cin>>lim;
		insertRandom(&arr,lim);
	} 
	system("CLS");
	cout<<"ARRAY MENU DRIVEN PROGRAM"<<endl<<endl;
	do
	{
		cout<<"\nPress: "<<endl;
		cout<<"1  to display the array"<<endl;
		cout<<"2  to append an element in the array."<<endl;
		cout<<"3  to insert an element at a particular index."<<endl;
		cout<<"4  to delete an element from a particular index."<<endl;
		cout<<"5  to linear Search an element."<<endl;
		cout<<"6  to use Optimised Linear Search(transposition) method."<<endl;
		cout<<"7  to use Optimised Linear Search(move to front) method."<<endl;
		cout<<"8  to use Iterative Binary Search to find an element."<<endl;
		cout<<"9  to use Recursive Binary Search to find an element."<<endl;
		cout<<"10 to get an element."<<endl;
		cout<<"11 to set an element."<<endl;
		cout<<"12 to find maximum element in the array."<<endl;
		cout<<"13 to find minimum element in the array."<<endl;
		cout<<"14 to find sum of all elements in the array."<<endl;
		cout<<"15 to find the average of all elements in the array."<<endl;
		cout<<"16 to reverse the array."<<endl;
		cout<<"17 to reorder the array based on condition."<<endl;
		cout<<"18 to left shift the array."<<endl;
		cout<<"19 to right shift the array."<<endl;
		cout<<"20 to left rotate the array."<<endl;
		cout<<"21 to right rotate the array."<<endl;
		cout<<"22 to insert a value in sorted array."<<endl;
		cout<<"23 to check if the array is sorted."<<endl;
		cout<<"24 to sort the array."<<endl;
		cin>>userIn;
		system("CLS");
		switch(userIn)
		{
			case 1:		cout<<"DISPLAYING THE ARRAY"<<endl;
						display(arr);
						break;
			case 2:		cout<<"APPENDING AN ELEMENT"<<endl;
						cout<<"Enter the element you want to append: ";
						cin>>x;
						append(&arr,x);
						break;
			case 3:		cout<<"INSERTING AN ELEMENT"<<endl;
						cout<<"Enter the element you want to insert: ";
						cin>>x;
						cout<<"Enter the index at which you want to insert: ";
						cin>>ind;
						insert(&arr,ind,x);
						break;
			case 4: 	cout<<"DELETING AN ELEMENT"<<endl;
						cout<<"Enter the index of the element you want to delete: ";
						cin>>ind;
						x = Delete(&arr,ind);
						if(x!=-1) cout<<x<<" deleted from index "<<ind<<endl;
						else cout<<"Deletion failed!! "<<endl;
						break;
			case 5:		cout<<"LINEAR SEARCH"<<endl;
						cout<<"Enter the element you want to search in the array: ";
						cin>>x;
						ind = linearSearch(arr,x);
						if(ind!=-1) cout<<"Element found! at index: "<<ind<<endl;
						else cout<<"Element NOT found!!"<<endl;
						break;
			case 6:		cout<<"OPTIMIZED LINEAR SEARCH (TRANSPOSITION)"<<endl;
						cout<<"Enter the element you want to search in the array: ";
						cin>>x;
						ind = linearSearchTransposition(&arr,x);
						if(ind!=-1)
						{
							cout<<"Element found! at index: "<<ind<<endl;
							if(ind!=0) cout<<"It is now moved to index: "<<ind-1<<endl;	
						} 
						else cout<<"Element NOT found!!"<<endl;
						break;
			case 7:		cout<<"OPTIMIZED LINEAR SEARCH (MOVE TO FRONT)"<<endl;
						cout<<"Enter the element you want to search in the array: ";
						cin>>x;
						ind = linearSearchMoveToFront(&arr,x);
						if(ind!=-1)
						{
							cout<<"Element found! at index: "<<ind<<endl;
							if(ind!=0) cout<<"It is now moved to index: 0"<<endl;
						}
						else cout<<"Element NOT found!!"<<endl;
						break;
			case 8:		cout<<"ITERATIVE BINARY SEARCH"<<endl;
						if(!sort)
						{
							cout<<"\nSorting the array to perform Binary Search..."<<endl;
							mergeSort(arr.A,0,arr.length-1);
							sort = 1;
						}
						cout<<"Enter the element you want to search in the array: ";
						cin>>x;
						ind = binarySearchIterative(arr,x);
						if(ind!=-1) cout<<"\nElement found! at index: "<<ind<<endl;
						else cout<<"Element NOT found!!"<<endl;
						break;
			case 9:		cout<<"RECURSIVE BINARY SEARCH"<<endl;
						if(!sort)
						{
							cout<<"\nSorting the array to perform Binary Search..."<<endl;
							mergeSort(arr.A,0,arr.length-1);
							sort = 1;
						}
						cout<<"Enter the element you want to search in the array: ";
						cin>>x;
						ind = binarySearchRecursive(arr.A,x,0,arr.length-1);
						if(ind!=-1) cout<<"\nElement found! at index: "<<ind<<endl;
						else cout<<"Element NOT found!!"<<endl;
						break;
			case 10:	cout<<"Enter the index of element you want to get: ";
						cin>>ind;
						get(arr,ind);
						break;	
			case 11:	cout<<"Enter the index of element you want to set: ";
						cin>>ind;
						cout<<"\nEnter the element you want to insert: ";
						cin>>x;
						set(&arr,ind,x);
						break;
			case 12:	cout<<"Maximum element in the array = "<<max(arr);
						break;
			case 13:	cout<<"Minimum element in the array = "<<min(arr);
						break;
			case 14:	summation = sum(arr);
						cout<<"Sum of all elements in the array = "<<summation;
						break;
			case 15:	average = avg(arr);
						cout<<"Average of the elements in the array = "<<average;
						break;
			case 16:	cout<<"Array before reverse: ";
						display(arr);
						reverse(&arr);
						cout<<"\n\nArray after reverse: ";
						display(arr);
						break;
			case 17: 	cout<<"Array before reorder: ";
						display(arr);
						cout<<"\n\nElements greater than x will be set on right side of array.";
						cout<<"\nEnter the value of x = ";
						cin>>x;
						reorder(&arr,x);
						cout<<"\n\nArray after reorder: ";
						display(arr);
						break;
			case 18:	cout<<"Array before left shift: ";
						display(arr); 
						leftShift(&arr);
						cout<<"\n\nArray after left shift: ";
						display(arr); 
						break;
			case 19:	cout<<"Array before right shift: ";
						display(arr); 
						rightShift(&arr);
						cout<<"\n\nArray after right shift: ";
						display(arr); 
						break;
			case 20:	cout<<"Array before left rotation: ";
						display(arr);
						leftRotate(&arr);
						cout<<"\n\nArray after left rotation: ";
						display(arr);
						break;
			case 21:	cout<<"Array before right rotation: ";
						display(arr);
						rightRotate(&arr);
						cout<<"\n\nArray after right rotation: ";
						display(arr);
						break;
			case 22:	if(isSorted(arr)==false)
						{
							cout<<"Sorting array...";
							mergeSort(arr.A,0,arr.length-1);
						}
						cout<<"\n\nEnter the element you want to insert: ";
						cin>>x;
						insertInSortedArray(&arr,x);
						break;
			case 23:	if(isSorted(arr)==true) cout<<"Array is sorted.";
						else cout<<"Array is unsorted.";
						break;
			case 24:	if(isSorted(arr)==true)
						{
							cout<<"Array is already sorted.";
						}
						else
						{
							mergeSort(arr.A,0,arr.length-1);
							cout<<"Array sorted.";
						} 
						break;
			default:	cout<<"Invalid Selection!!";
						break;
		}			
		cout<<"\n\nPress 1 to continue and any other key to exit: ";
		cin>>userIn;
		if(userIn!=1) userIn = 0;
	}while(userIn);
	delete arr.A;
	return 0;
}
