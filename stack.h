<<<<<<< HEAD
#ifndef STACKARR_H
#define STACKARR_H

#include "circulararray.h"

template <typename T>
class StackArray: public CircularArray<T> { 
    public:
        StackArray<T>(): CircularArray<T>(0){};

        StackArray<T>(int _capacity): CircularArray<T>(_capacity){};

        ~StackArray(){
        };

        void stack_push_back(T data){
          this->push_back(data);
        };

        T stack_pop_back(){
          return this->pop_back();
        };

        string stack_to_string(){
          return this->to_string();
        };
};
#endif
=======
#ifndef STACKARR_H
#define STACKARR_H

#include "circulararray.h"

template <typename T>
class StackArray: public CircularArray<T> { 
    public:
        StackArray<T>(): CircularArray<T>(0){};

        StackArray<T>(int _capacity): CircularArray<T>(_capacity){};

        ~StackArray(){
        };

        void stack_push_back(T data){
          this->push_back(data);
        };

        T stack_pop_back(){
          return this->pop_back();
        };

        string stack_to_string(){
          return this->to_string();
        };
};

>>>>>>> d37b28edc9cf68daac4b724a24bf8a49372c1734
#endif