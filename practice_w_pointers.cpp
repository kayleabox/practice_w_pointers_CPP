//use pointers and dynamic memory allocation to create, fill and sort arrays of random numbers
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

class Array_Class{
	private:
		int size = 0;
		int *array_pointer;
		int **asc_array_pointer, 
		**desc_array_pointer;
		//sorts
		void ascBubbleSort(int *array[], int size);
		void descBubbleSort(int *array[], int size);
	public:
		Array_Class(){}
		Array_Class(int size);
		~Array_Class();
		void show_array_ptr();
};

char get_char(string prompt,string badch_errmsg,string range_errmsg, char char1, char char2);
int get_int(string prompt,string badch_errmsg,string range_errmsg, int lo, int hi);

int main(){
	
	//get a seed value for random numbers to fill array
	int seed = time(0);
	srand(seed);

	char input = 'y';
	while (input == 'y'){
		cout<<"would you like to fill and sort an array?\n";
		input = get_char("enter","invalid input","input out of range ", 'y', 'n');
		if (input == 'n')
			{break;}
		int size = get_int("enter the size of the array you wish to sort", "invalid input. ", "input out of range. ", 0, 20);

		cout<<"this is the dynamically allocated array.\n";
		Array_Class array_of_num(size);
		cout<<"this is the original again.\n";
		array_of_num.show_array_ptr();
		cout << endl;
	}

	return 0;	

}

Array_Class::Array_Class(int size){
	this->size = size;
	array_pointer = new int[size]; //dynamically allocate array
	//fill array with rand num
	for (int n = 0; n < size; n++){
		array_pointer[n]=rand();
		cout<<array_pointer[n]<<" ";		
	}
	cout<<endl;
	//dynamically allocate an array for the ascending sort 	
	asc_array_pointer = new int*[size];
	for (int n = 0; n < size; n++){
		asc_array_pointer[n]=&array_pointer[n];
	}
	//dynamically allocate an array for the desscending sort 
	desc_array_pointer = new int*[size];
	for (int n = 0; n < size; n++){
		desc_array_pointer[n]=&array_pointer[n];
	}
	//sort the array
	ascBubbleSort(asc_array_pointer, size);
	descBubbleSort(desc_array_pointer, size);
}

Array_Class::~Array_Class(){
	//delete the dynamically allocated arrays
	cout<<"dynamically allocated pointers are being deleted.\n";
	delete [] array_pointer;
	delete [] asc_array_pointer;
	delete [] desc_array_pointer;
}

void Array_Class::show_array_ptr(){
	for (int n = 0; n < size; n++){
		cout<<array_pointer[n]<<" ";
	}
	cout<<endl;
}


void Array_Class::ascBubbleSort(int *array[], int size)
{
	//var to copy the values to for swapping
	int *holderVar; //it will hold the values so they are not lost when writing them to new locations in the array
	bool swapPlaces; 
	do 
	{
		swapPlaces = false; 
		for(int index = 0; index < (size-1); index++)//the comparisons stop at index-1 to avoid going past the end of the array
		{
			if (*array[index] > *array[index + 1])//if this is true the values will be swapped because they are not in order
			{
				holderVar = array[index]; //copy the the value of array[index] to holderVar so it can be swapped
				array[index] = array[index + 1]; //since array[index]==holderVar we can copy the value of array[index+1] to array[index]
				array[index + 1] = holderVar; //now we can move the original value now stored in holderVar into its new spot, array[index+1]
				swapPlaces = true; //we had to swap so swap is true because array[index] was > array[index+1]
			}
		}
		
	}
	while (swapPlaces);
	//show the sorted array
	cout<<"this is the ascending array.\n";
	for (int index = 0; index < (size); index++){
		cout<<*array[index]<<" ";
	}
	cout<<endl;
}

void Array_Class::descBubbleSort(int *array[], int size)
{
	//var to copy the values to for swapping
	int *holderVar; //it will hold the values so they are not lost when writing them to new locations in the array
	bool swapPlaces; 
	do 
	{
		swapPlaces = false; 
		for(int index = 0; index < (size-1); index++)
		{
			if (*array[index] < *array[index + 1])//if this is true the values will be swapped because they are not in order
			{
				holderVar = array[index]; //copy the the value of array[index] to holderVar so it can be swapped
				array[index] = array[index + 1]; //since array[index]==holderVar we can copy the value of array[index+1] to array[index]
				array[index + 1] = holderVar; //now we can move the original value now stored in holderVar into its new spot, array[index+1]
				swapPlaces = true; //we had to swap so swap is true because array[index] was < array[index+1]
			}
		}
		
	}
	while (swapPlaces);
	//show the sorted array
	cout<<"this is the descending array.\n";
	for (int index = 0; index < (size); index++){
		cout<<*array[index]<<" ";
	}
	cout<<endl;
}

//get character inputs and check errors
char get_char(string prompt,string badch_errmsg,string range_errmsg, char char1, char char2)
{
	char user_input;
	while(user_input!= char1 or user_input!=char2) 
	{
	    cout<<prompt<<" "<<char1<<" or "<<char2<<": ";
	    if (cin>>user_input) 
		{
			user_input = tolower(user_input);
	    	if (user_input==char1 or user_input==char2)
	        	return user_input;
	      else
	        cout<<range_errmsg;
	    } 
		else 
		{
	      cout<<badch_errmsg;
	      cin.clear(); cin.ignore(1024, '\n');
	    }
	}
}

//get integer inputs and check for errors
int get_int(string prompt,string badch_errmsg,string range_errmsg, int lo, int hi)
{
	while (true) 
	{
		int user_int_input=0;
	    cout<<prompt<<"("<<lo<<"-"<<hi<<"): ";
	    if (cin>>user_int_input) 
		{
	    	if (user_int_input>=lo and user_int_input<=hi)
	        	return user_int_input;
	      else
	        cout<<range_errmsg;
	    } 
		else 
		{
	      cout<<badch_errmsg;
	      cin.clear(); cin.ignore(1024, '\n');
	    }
	}
}

/*
would you like to fill and sort an array?
enter y or n: y
enter the size of the array you wish to sort(0-20): 5
this is the dynamically allocated array.
8184 707 15787 20874 15580
this is the ascending array.
707 8184 15580 15787 20874
this is the descending array.
20874 15787 15580 8184 707
this is the original again.
8184 707 15787 20874 15580

dynamically allocated pointers are being deleted.
would you like to fill and sort an array?
enter y or n: y
enter the size of the array you wish to sort(0-20): 30
input out of range. enter the size of the array you wish to sort(0-20): 10
this is the dynamically allocated array.
26630 14678 15980 12229 22236 14692 28370 18986 19757 11567
this is the ascending array.
11567 12229 14678 14692 15980 18986 19757 22236 26630 28370
this is the descending array.
28370 26630 22236 19757 18986 15980 14692 14678 12229 11567
this is the original again.
26630 14678 15980 12229 22236 14692 28370 18986 19757 11567

dynamically allocated pointers are being deleted.
would you like to fill and sort an array?
enter y or n: n

--------------------------------
Process exited after 15.31 seconds with return value 0
Press any key to continue . . .
*/
