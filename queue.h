<<<<<<< HEAD
#ifndef QUEUEARR_H
#define QUEUEARR_H

#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
  public:
      QueueArray<T>(): CircularArray<T>(0){};

      QueueArray<T>(int _capacity): CircularArray<T>(_capacity){};

      ~QueueArray(){
      };

      void queue_push_back(T data){
        this->push_back(data);
      };

      T queue_pop_front(){
        return this->pop_front();
      };

      string queue_to_string(){
          return this->to_string();
      };
};
#endif
=======
#ifndef QUEUEARR_H
#define QUEUEARR_H

#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
  public:
      QueueArray<T>(): CircularArray<T>(0){};

      QueueArray<T>(int _capacity): CircularArray<T>(_capacity){};

      ~QueueArray(){
      };

      void queue_push_back(T data){
        this->push_back(data);
      };

      T queue_pop_front(){
        return this->pop_front();
      };

      string queue_to_string(){
          return this->to_string();
      };
};

>>>>>>> d37b28edc9cf68daac4b724a24bf8a49372c1734
#endif