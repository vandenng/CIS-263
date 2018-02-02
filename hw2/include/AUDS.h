//Author: Nathan Vanden Hoek

#include <iostream>

#define INITIALSIZE 100 // The initial size of the AUDS.
#define EMPTY -1 //Used to show that there is no item needed to be deleted.

/********************************************************************************************
 *This is an AUDS(Almost Useless Data Structure). An AUDS will hold any type of object,
 *through the use of the class template. This data structure will return a random
 *item from the list. The initial size is set to 100, and everytime the AUDS gets resized,
 *it will resize by 50% more than the current size of AUDS. 
 *******************************************************************************************/
template<class T>
class AUDS{
	public:
		/********************************************************************************************
		 *This is the default constructor. This will initalize the AUDS data to 100 items, and
		 *the current size of the ADUS is set to 0.
		 *******************************************************************************************/
		AUDS(){
			srand((int)time(NULL));	
			this->data = new T[this->totalSize];
			this->currentSize = 0;
		}

		/********************************************************************************************
		 *This is the deconstructor. This will return the allocated memory back to the OS.
		 *******************************************************************************************/
		 ~AUDS(){
			delete[] this->data;
		}

		/********************************************************************************************
		 *This will copy the constructor. It will copy the data and current size of the given
		 *AUDS to this AUDS.
		 *******************************************************************************************/
		 AUDS(const AUDS &other){
			this->currentSize = other.currentSize;
			this->totalSize = other.totalSize;
			this->data = new T[this->currentSize];
			for(int i = 0; i < this->currentSize; i++)
				this->data[i] = other.data[i];
		}
		
		/********************************************************************************************
		 *This will copy the constructor. It will copy the data and current size of the given
		 *AUDS to this AUDS.
		 *******************************************************************************************/
		AUDS& operator=(AUDS other){
			std::swap(this->data, other.data);
			std::swap(this->totalSize, other.totalSize);
			std::swap(this->currentSize, other.currentSize);

			return *this;
		}

		/********************************************************************************************
		 *This will calculate the current size of the AUDS by counting each element located 
		 *in this list.
		 *******************************************************************************************/
		int size(){
			return this->currentSize;
		}

		/********************************************************************************************
		 *This will add a generic object to the AUDS.
		 *******************************************************************************************/
		void push(const T& x){
			if(this->currentSize == this->totalSize){
				this->totalSize = this->currentSize + (this->currentSize / 2);
				this->resize();	
			}
			
			this->data[this->currentSize++] = x;	
			return;	
		}

		/********************************************************************************************
		 *This will return a random element in the AUDS and delete it from AUDS. This is
		 *done by pointing to the dealted element, and then resizeing the origanal AUDS, and
		 *returns a reference to the deleted element. If the AUDS is empty, this method will
		 *throw an error message.
		 *******************************************************************************************/
		T& pop(){
			if(this->currentSize == 0){
				throw "ERROR: Emtpy AUDS"; //This is how I threw exeptions in C & figured it would work here.
			}
			
			//This will only give a remainder <= to the current size of the AUDS.
			this->deleted = rand() % (this->currentSize) + 0;

			//Check to see if the element has been deleted before.
			while(this->data[this->deleted] == T())
				this->deleted = rand() % (this->currentSize) + 0;

			T* temp = new T[1];
			temp[0] = *(this->data  + this->deleted);
	
			this->resize();
			this->currentSize--;
			this->deleted = EMPTY;		
	
			return *temp;
		}

	private:	
		int totalSize = INITIALSIZE; //The size of the entire list
		int currentSize; //the current size of the AUDS
		int deleted = EMPTY; //The number that will represent the elment to be deleted in the AUDS.
		T* data; //The data in the AUDS

		/********************************************************************************************
		 *This will resize the data to 50% more than what it origanally was. EX: 100 -> 150
		 *resize will only be called when the AUDS is full, and the push function is called
		 *again.
		 *******************************************************************************************/
		void resize(){					
			T* arr = new T[this->totalSize];
	
			for(int i = 0; i < this->currentSize; i++){
				if(i != this->deleted) 
					arr[i] = *(this->data + i);
			}
			
			delete[] this->data;
			this->data = arr;
		}
};
