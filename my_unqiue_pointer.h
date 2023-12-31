//
// Created by ding on 12/29/23.
//

#ifndef GOOGLE_TESTS_MY_UNQIUE_POINTER_H
#define GOOGLE_TESTS_MY_UNQIUE_POINTER_H
#include <iostream>  //main header

template <typename T>
class my_unique_pointer {
private:
  T * data;

public:
  my_unique_pointer(T *p) {
    std::cout << " my_unique_pointer(T *p)" <<std::endl;
    data = p;
  }

  //A(B) delete
  my_unique_pointer(const my_unique_pointer& rhs) = delete;
  //A = B = C delete
  my_unique_pointer& operator = (const my_unique_pointer& rhs) = delete;

  my_unique_pointer& operator = (my_unique_pointer&& rhs) {
    std::cout << "my_unique_pointer& operator = (const my_unique_pointer&& rhs) " <<std::endl;
    data = std::move(rhs.data);
    rhs.data = nullptr;
    return (*this);
  }

  my_unique_pointer(my_unique_pointer && rhs) {
    std::cout << " my_unique_pointer(my_unique_pointer && rhs)" <<std::endl;
    data = std::move(rhs.data);
    rhs.data = nullptr;
  }

  // *A : support compare
  T& operator *() {
    return (*data);
  }

  T* operator ->() {

    return data;
  }

  ~my_unique_pointer() {
    std::cout << " ~my_unique_pointer()" << data << std::endl;
    if (data)
      delete data;

    data = nullptr;
  }

};


#endif //GOOGLE_TESTS_MY_UNQIUE_POINTER_H
