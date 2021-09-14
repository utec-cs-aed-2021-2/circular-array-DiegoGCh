#ifndef CIRCULARARR_H
#define CIRCULARARR_H


#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
    private:
        T *array;
        int capacity;
        int back, front;
        
    public:
        CircularArray();
        CircularArray(int _capacity);
        virtual ~CircularArray();
        T get_front();
        T get_back();
        void push_front(T data);
        void push_back(T data);
        void insert(T data, int pos);
        T pop_front();
        T pop_back();
        bool is_full();
        bool is_empty();
        int size();
        void resize();
        void clear();
        T &operator[](int);
        void heapify(int* arr, int size, int i); //para el heapsort
        void sort();
        bool is_sorted();
        void reverse();
        string to_string(string sep=" ");


    private:
        int next(int);
        int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
bool CircularArray<T>::is_full(){
    return next(this->back) == this->front;
}

template <class T>
bool CircularArray<T>::is_empty(){
    return ((this->back == -1) && (this->front == -1));
}

template <class T>
int CircularArray<T>::size(){
    if (is_empty() == false){
        int sz = 0;
        if (this->front > this->back){
            sz = this->capacity - this->front + this->back+ 1;
        } else{
            sz = this->back - this->front + 1;
        } return sz;
    } else {
        return 0;
    }
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}

template <class T>
T& CircularArray<T>::operator[](int index){
    return array[(this->front + index) % this->capacity];
}

template <class T>
T CircularArray<T>::get_front(){
  return this->array[this->front];
}

template <class T>
T CircularArray<T>::get_back(){
  return this->array[this->back];
}

template <class T>
void CircularArray<T>::clear(){
  this->front = this->back = -1;
}

template <class T>
T CircularArray<T>::pop_front(){
    if (is_empty() == false){
      if (this->front == this->back){
        T frnt = this->array[this->front];
        this->front = this->back = -1;
        return frnt;
      } else {
        T frnt = this->array[this->front];
        this->front = next(this->front);
        return frnt;
      }
    } else {
        cout << endl << "Is empty." << endl;
        return 0; //que retorna si es empty?
    }
}

template <class T>
T CircularArray<T>::pop_back(){
  if (is_empty() == false){
    if (this->front == this->back){
      T bck = this->array[this->back];
      this->front = this->back = -1;
      return bck;
    } else {
      T bck = this->array[this->back];
      this->back = prev(this->back);
      return bck;
    }
  } else {
    cout << endl << "Is empty." << endl;
    return 0; //que retorna si es empty??
  }
}

template <class T>
void CircularArray<T>::resize(){
  int *temp = new T[this->capacity * 2];

  for (int i = 0; i < this->capacity; i++){
    temp[i] = this->array[(i+1) % this->capacity];
  } 
  
  delete[] this->array;
  this->array = temp;

  this->back = this->capacity - 1;
  this->front = 0;
  this->capacity = this->capacity * 2;
}

template <class T>
void CircularArray<T>::push_front(T data){
  if (is_full()){
    resize();
  }
  if (is_empty() == false){
    this->front = prev(this->front);
  } else {
    this->front = this->back = 0;
  }
    this->array[this->front] = data;
 }

template <class T>
void CircularArray<T>::push_back(T data){
  if (is_full()){
    resize();
  }
  if (is_empty() == false){
      this->back = next(this->back);
  } else {
      this->front = this->back = 0;
  }
  this->array[this->back] = data;
}

template <class T>
void CircularArray<T>::insert(T data, int pos){
  /*
  this->array[(pos % size()) + this->front] = data;
  */
  if (is_full()){
    resize();
  }
  if (is_empty() == false){
    int i = next(this->back);
    this->back = next(this->back);
    while (i != ((pos % size()) + this->front)){
      this->array[i] = this->array[prev(i)];
      cout << endl << this->array[i] <<endl;
      i = prev(i);
    }
    this->array[((pos % size()) + this->front)] = data;
  }
}

template <class T>
void CircularArray<T>::heapify(int* arr, int size, int i){
    int valor_max = i; // Toma al nodo raiz como valor_max
    int hijo_izq = 2 * i + 1; // left = 2 * i + 1
    int hijo_der = 2 * i + 2; // right = 2 * i + 2
 
    //Verifica si el hijo izq es mayor al valor_max
    if (hijo_izq < size && arr[hijo_izq] > arr[valor_max])
        valor_max = hijo_izq; //Si lo es, valor max toma el indice del hijo
 
    //Lo mismo para el hijo derecho
    if (hijo_der < size && arr[hijo_der] > arr[valor_max])
        valor_max = hijo_der;
 
    //Si es que el valor maximo no terminó siendo el que se ingresó, intercambian lugares en el array
    if (valor_max != i) {
        swap(arr[i], arr[valor_max]);
 
        //Se aplica heapify recursivamente en el arbol, ahora a partir del nuevo subarbol
        heapify(arr, size, valor_max);
    }
}


template <class T>
void CircularArray<T>::sort(){ //para que funcione bien tuve que poner los front y back en los indices 0 y size()-1, respectivamente
  this->back = size()-1;
  this->front = 0;

  for (int i = (size() - 1) / 2; i >= 0; i--){
    heapify(this->array, size(), i);
  }
  
  for (int i = size() - 1; i > 0; i--){
    swap(this->array[0], this->array[i]);

    heapify(this->array, i, 0);
  }
}

template <class T>
bool CircularArray<T>::is_sorted(){
  T* arr_sort = new T[size()];
  for (int i = 0; i < size(); i++){
    arr_sort[i] = this->array[i];
  }
  for (int i = (size() - 1) / 2; i >= 0; i--)
    heapify(arr_sort, size(), i);

  for (int i = size() - 1; i > 0; i--){
    swap(arr_sort[0], arr_sort[i]);

    heapify(arr_sort, i, 0);
  }
  for (int i = 0; i < size(); i++){
    if (arr_sort[i] != this->array[i]){
      delete[] arr_sort;
      return false;
    }
  }
  delete[] arr_sort;
  return true;
}

template <class T>
void CircularArray<T>::reverse(){
  for (int bajo = 0, alto = size()-1; bajo < alto; bajo++, alto--){
    swap(this->array[bajo], this->array[alto]);
  }
}

#endif