#pragma once

template<typename T>
class gArr {

private:
	unsigned cap;
	unsigned nrOfEl;
	unsigned initalCap;
	T* *arr;

	void expand();
	void initialize(unsigned from);



public:
	gArr(unsigned size = 5);
	gArr(const gArr& obj0);
	~gArr();

	T& operator[] (const unsigned index);
	void operator= (const gArr& obj);

	unsigned maxCap();
	unsigned size();
	void push(const T element);
	void remove(const unsigned index, bool ordered = false);

};
template<typename T>
gArr<T>::gArr(unsigned size) {

	this->initalCap = size;
	this->cap = size;
	this->nrOfEl = 0;

	this->arr = new T * [this->cap];

	this->initialize(0);
}

template<typename T>
gArr<T>::gArr(const gArr& obj) {

	this->initalCap = obj.initialCap;
	this->cap = obj.cap;
	this->nrOfEl = obj.nrOfEl;

	this->arr = new T * [this->cap];
	for (size_t i = 0; i < this->nrOfEl; i++) {

		this->arr[i] = new  T(*obj.arr[i]);
	}
	this->initialize(0);
}

template<typename T>
gArr<T>::~gArr() {
	for (size_t i = 0; i < this->nrOfEl; i++) {

		delete this->arr[i];
	}
	delete[] arr;
}

template<typename T>
T& gArr<T>::operator[] (const unsigned index) {

	if (index < 0 || index >= this->nrOfEl)
		throw "Auserhalb des genunden index Opterator";

	return *this->arr[index];
}

template<typename T>
void gArr<T>::operator = (const gArr& obj) {

	for (size_t i = 0; i < this->nrOfEl; i++) {

		delete this->arr[i];
	}
	delete[] arr;

	this->initalCap = obj.initialCap;
	this->cap = obj.cap;
	this->nrOfEl = obj.nrOfEl;

	this->arr = new T * [this->cap];
	for (size_t i = 0; i < this->nrOfEl; i++) {

		this->arr[i] = new  T(*obj.arr[i]);
	}
	this->initialize(0);

}

template<typename T>
void gArr<T>::expand() {

	this->cap *= 2;

	T** tempArr = new T * [this->cap];
	
	for (size_t i = 0; i < this->nrOfEl; i++) {

		tempArr[i] = this->arr[i];
	}

	delete[]arr;

	this->arr = tempArr;

	this->initialize(this->nrOfEl);

}



template<typename T>
void gArr<T>::initialize(unsigned from) {

	for (size_t i = 0; i < this->cap; i++) {

		this->arr[i] = nullptr;
	}

}

template<typename T>
unsigned gArr<T>::maxCap() {

	return this->cap;
}

template<typename T>
unsigned gArr<T>::size() {

	return this->nrOfEl;
}

template<typename T>
void gArr<T>::push(const T element) {

	if (this->nrOfEl >= this->cap)
		this->expand();

	this->arr[this->nrOfEl++] = new T(element);
	

}

template<typename T>
void gArr<T>::remove(const unsigned index, bool ordered ) {

	if (index < 0 || index >= this->nrOfEl)
		throw "out of bounds remove";
	if (ordered) {

		delete this->arr[index];

		for (size_t i = 0; i < this->nrOfEl -1; i++) {

			this->arr[i] = this->arr[i + 1];

		}
		this->arr[--this->nrOfEl] = nullptr;
	}
	else {
		delete this->arr[index];
		


		this->arr[index] = this->arr[this->nrOfEl - 1];

		this->arr[--this->nrOfEl] = nullptr;
	}
}