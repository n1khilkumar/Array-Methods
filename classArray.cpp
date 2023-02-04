#include<iostream>
#include<time.h>
using namespace std;

template<class T>
class array
{
	private:
		int *A;
		int size;
		int length;
		
	public:
		array()
		{
			size = 10;
			A = new int[10];
			length = 0;
		}
		array(int sz,int ln)
		{
			size = sz;
			A = new int[size];
			length = ln;
		}
		~array()
		{
			delete []A;
		}
		int returnLength();
		void insertRandom(T lim);
		void insertManually();
		void display();
		void append(T x);
		void insert(int ind,T x);
		T Delete(int ind);
		int linearSearch(T key);
		int linearSearchTransposition(T key);
		int linearSearchMoveToFront(T key);
		int binarySearchIterative(T key);
		int binarySearchRecursive(T key,int low,int high);
		void merging(int low,int mid,int high);
		void mergeSort(int low,int high);
		void get(int ind);
		void set(int ind,T x);
		T max();
		T min();
		T sum();
		long double avg();
		void reverse();
		void reorder(T value);
		void leftShift();
		void rightShift();
		void leftRotate();
		void rightRotate();
		void insertInSortedArray(T x);
		bool isSorted();
};

void swap(int *num1,int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

template<class T>
int array<T>::returnLength()
{
	return length;
}
		
template<class T>
void array<T>::insertRandom(T lim)
{
	srand(time(0));
	for(int i=0;i<length;i++)
	{
		A[i] = rand()%lim; 
	}
}

template<class T>
void array<T>::insertManually()
{
	cout<<endl;
	for(int i=0;i<length;i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>A[i];
	}
}

template<class T>
void array<T>::display()
{
	cout<<"\nElements in the array are: ";
	for(int i=0;i<length;i++)
	{
		cout<<A[i]<<" ";
	}
}

template<class T>
void array<T>::append(T x)
{
	if(length<size)
	{
		A[length++] = x;
		cout<<"\nElement added at index: "<<length-1;
	}
	else cout<<"\nArray is full, can't add more elements.";
}

template<class T>
void array<T>::insert(int ind,T x)
{
	if(ind>=0&&ind<=length)
	{
		for(int i=length-1;i>=ind;i--)            
		{								
			A[i+1] = A[i];
		}
		A[ind] = x;
		length++;
		cout<<"\nElement added";
	}
	else cout<<"\nCan't insert at this index.";
}

template<class T>
T array<T>::Delete(int ind)
{
	int del = -1;
	if(ind>=0&&ind<=length)
	{
		del = A[ind];
		for(int i=ind;i<length-1;i++)
		{
			A[i] = A[i+1];
		}
		length--;
	}
	return del;
}

template<class T>
int array<T>::linearSearch(T key)
{
	for(int i=0;i<length;i++)
	{
		if(A[i] == key) return i;
	}
	return -1;
}

template<class T>
int array<T>::linearSearchTransposition(T key)
{
	for(int i=0;i<length;i++)
	{
		if(A[i] == key)
		{
			if(i>0) swap(&A[i],&A[i-1]);
			return i;
		}
	}
	return -1;
}

template<class T>
int array<T>::linearSearchMoveToFront(T key)
{
	for(int i=0;i<length;i++)
	{
		if(A[i] == key)
		{
			if(i!=0) swap(&A[i],&A[0]);
			return i;
		}
	}
	return -1;
}

template<class T>
int array<T>::binarySearchIterative(T key)
{
	int low = 0, high = length-1,mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(A[mid] == key) return mid;
		else if(A[mid] < key) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

template<class T>
int array<T>::binarySearchRecursive(T key,int low,int high)
{
	if(low<=high)
	{
		int mid = low + (high-low)/2;
		if(A[mid] == key) return mid;
		else if(A[mid]>key) return binarySearchRecursive(key,low,mid-1);
		else return binarySearchRecursive(key,mid+1,high);
	}
	return -1;
}

template<class T>
void array<T>::merging(int low,int mid,int high)
{
	T B[high+1],i=low,j=mid+1,k=low;	
	while(i<=mid&&j<=high)				
	{
		if(A[i]<A[j]) B[k++] = A[i++];
		else B[k++] = A[j++];
	}
	while(i<=mid) B[k++] = A[i++];		
	while(j<=high) B[k++] = A[j++];
	for(i=low;i<=high;i++) A[i] = B[i];	
}

template<class T>
void array<T>::mergeSort(int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;			
		mergeSort(low,mid);
		mergeSort(mid+1,high);
		merging(low,mid,high);
	}
}

template<class T>
void array<T>::get(int ind)
{
	if(ind>=0 && ind<length) cout<<A[ind];
	else cout<<"\nInvalid Index!";
}

template<class T>
void array<T>::set(int ind,T x)
{
	if(ind>=0 && ind<length)
	{
		A[ind] = x;
		cout<<"\nElement Set!";
	} 
	else cout<<"\nInvalid Index!";
}

template<class T>
T array<T>::max()
{
	int maximum = A[0];
	for(int i=1;i<length;i++)
	{
		if(A[i]>maximum) maximum = A[i];
	}
	return maximum;
}

template<class T>
T array<T>::min()
{
	int minimum = A[0];
	for(int i=1;i<length;i++)
	{
		if(A[i]<minimum) minimum = A[i];
	}
	return minimum;
}

template<class T>
T array<T>::sum()
{
	T sum = 0;
	for(int i=0;i<length;i++) sum = sum + A[i];
	return sum;
}

template<class T>
long double array<T>::avg()
{
	T summation = array::sum();
	long double average = double(summation)/double(length);
	return average;
}

template<class T>
void array<T>::reverse()
{
	for(int i=0,j=length-1 ; i<j; i++,j--)
	{
		swap(&A[i],&A[j]);
	}
}

template<class T>
void array<T>::reorder(T value)
{
	int i = 0,j = length-1;
	while(i<j)
	{
		while(A[i]<=value) i++;
		while(A[j]>value) j--;
		if(i<j) swap(&A[i++],&A[j--]);
	}
}

template<class T>
void array<T>::leftShift()
{
	for(int i=0;i<length-1;i++)
	{
		A[i] = A[i+1];
	}
	A[length-1] = 0;
}

template<class T>
void array<T>::rightShift()   
{									
	for(int i=length-1;i>0;i--)
	{
		A[i] = A[i-1];
	}
	A[0] = 0;
}

template<class T>
void array<T>::leftRotate()
{
	T temp = A[0];
	for(int i=0;i<length-1;i++)
	{
		A[i] = A[i+1];
	}
	A[length-1] = temp;
}

template<class T>
void array<T>::rightRotate()
{
	T temp = A[length-1];
	for(int i=length-1;i>0;i--)
	{
		A[i] = A[i-1];
	}
	A[0] = temp;
}

template<class T>
void array<T>::insertInSortedArray(T x)
{
	if(length<size) 
	{
		int i = length-1;
		while(A[i]>x)
		{
			A[i+1] = A[i--];
		}
		A[i+1] = x;
		cout<<"\nValue inserted.";
		length++;
	}
	else cout<<"\nArray at max size can't insert more elements.";
}

template<class T>
bool array<T>::isSorted()
{
	for(int i=0;i<length-1;i++)
	{
		if(A[i]>A[i+1]) return false;
	}
	return true;
}

int main()
{
	int userIn,lim,x,ind,sort = 0,size,length;
	long long int summation;
	long double average;
	cout<<"ARRAY MENU DRIVEN PROGRAM"<<endl<<endl;
	cout<<"\nEnter the size of the array: ";
	cin>>size;
	cout<<"Enter the number of elements you want to insert: ";
	cin>>length;
	array<int> arr(size,length);
	do
	{
		cout<<"\nPress: "<<endl;
		cout<<"1 to Manually insert elements."<<endl;
		cout<<"2 to Randomly insert elements."<<endl;
		cin>>userIn;
	}while(userIn!=1&&userIn!=2);
	if(userIn == 1) arr.insertManually();
	else
	{
		cout<<"\nEnter the maximum limit you want for an element: ";
		cin>>lim;
		arr.insertRandom(lim);
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
						arr.display();
						break;
			case 2:		cout<<"APPENDING AN ELEMENT"<<endl;
						cout<<"Enter the element you want to append: ";
						cin>>x;
						arr.append(x);
						break;
			case 3:		cout<<"INSERTING AN ELEMENT"<<endl;
						cout<<"Enter the element you want to insert: ";
						cin>>x;
						cout<<"Enter the index at which you want to insert: ";
						cin>>ind;
						arr.insert(ind,x);
						break;
			case 4: 	cout<<"DELETING AN ELEMENT"<<endl;
						cout<<"Enter the index of the element you want to delete: ";
						cin>>ind;
						x = arr.Delete(ind);
						if(x!=-1) cout<<x<<" deleted from index "<<ind<<endl;
						else cout<<"Deletion failed!! "<<endl;
						break;
			case 5:		cout<<"LINEAR SEARCH"<<endl;
						cout<<"Enter the element you want to search in the array: ";
						cin>>x;
						ind = arr.linearSearch(x);
						if(ind!=-1) cout<<"Element found! at index: "<<ind<<endl;
						else cout<<"Element NOT found!!"<<endl;
						break;
			case 6:		cout<<"OPTIMIZED LINEAR SEARCH (TRANSPOSITION)"<<endl;
						cout<<"Enter the element you want to search in the array: ";
						cin>>x;
						ind = arr.linearSearchTransposition(x);
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
						ind = arr.linearSearchMoveToFront(x);
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
							arr.mergeSort(0,arr.returnLength()-1);
							sort = 1;
						}
						cout<<"Enter the element you want to search in the array: ";
						cin>>x;
						ind = arr.binarySearchIterative(x);
						if(ind!=-1) cout<<"\nElement found! at index: "<<ind<<endl;
						else cout<<"Element NOT found!!"<<endl;
						break;
			case 9:		cout<<"RECURSIVE BINARY SEARCH"<<endl;
						if(!sort)
						{
							cout<<"\nSorting the array to perform Binary Search..."<<endl;
							arr.mergeSort(0,arr.returnLength()-1);
							sort = 1;
						}
						cout<<"Enter the element you want to search in the array: ";
						cin>>x;
						ind = arr.binarySearchRecursive(x,0,arr.returnLength()-1);
						if(ind!=-1) cout<<"\nElement found! at index: "<<ind<<endl;
						else cout<<"Element NOT found!!"<<endl;
						break;
			case 10:	cout<<"Enter the index of element you want to get: ";
						cin>>ind;
						arr.get(ind);
						break;	
			case 11:	cout<<"Enter the index of element you want to set: ";
						cin>>ind;
						cout<<"\nEnter the element you want to insert: ";
						cin>>x;
						arr.set(ind,x);
						break;
			case 12:	cout<<"Maximum element in the array = "<<arr.max();
						break;
			case 13:	cout<<"Minimum element in the array = "<<arr.min();
						break;
			case 14:	summation = arr.sum();
						cout<<"Sum of all elements in the array = "<<summation;
						break;
			case 15:	average = arr.avg();
						cout<<"Average of the elements in the array = "<<average;
						break;
			case 16:	cout<<"Array before reverse: ";
						arr.display();
						arr.reverse();
						cout<<"\n\nArray after reverse: ";
						arr.display();
						break;
			case 17: 	cout<<"Array before reorder: ";
						arr.display();
						cout<<"\n\nElements greater than x will be set on right side of array.";
						cout<<"\nEnter the value of x = ";
						cin>>x;
						arr.reorder(x);
						cout<<"\n\nArray after reorder: ";
						arr.display();
						break;
			case 18:	cout<<"Array before left shift: ";
						arr.display(); 
						arr.leftShift();
						cout<<"\n\nArray after left shift: ";
						arr.display(); 
						break;
			case 19:	cout<<"Array before right shift: ";
						arr.display(); 
						arr.rightShift();
						cout<<"\n\nArray after right shift: ";
						arr.display(); 
						break;
			case 20:	cout<<"Array before left rotation: ";
						arr.display();
						arr.leftRotate();
						cout<<"\n\nArray after left rotation: ";
						arr.display();
						break;
			case 21:	cout<<"Array before right rotation: ";
						arr.display();
						arr.rightRotate();
						cout<<"\n\nArray after right rotation: ";
						arr.display();
						break;
			case 22:	if(arr.isSorted()==false)
						{
							cout<<"Sorting array...";
							arr.mergeSort(0,arr.returnLength()-1);
						}
						cout<<"\n\nEnter the element you want to insert: ";
						cin>>x;
						arr.insertInSortedArray(x);
						break;
			case 23:	if(arr.isSorted()==true) cout<<"Array is sorted.";
						else cout<<"Array is unsorted.";
						break;
			case 24:	if(arr.isSorted()==true)
						{
							cout<<"Array is already sorted.";
						}
						else
						{
							arr.mergeSort(0,arr.returnLength()-1);
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
	arr.~array();
	return 0;
}
