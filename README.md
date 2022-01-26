# CS-225
Data Structures. Enjoy these labs and mps, and please do not pull an all nighter for the labs.

# Understanding Data Structures: Lectures
Below are the notes that I took for Data Structures @UIUC.

## Lectures:
<details> <summary> Click for ALL NOTES </summary>
  
  ### Lecture 1: Introduction jan 19 (1/14)
  <details> <summary> <span style="color: green"> Lecture 1 </span> </summary>

  #### Variables Description
  > Variables in C++ are defined by Name, Type, Locations in Memory, and Value

  #### Variable Types
  > Variables can be primitive (int, char, double, boolean, float, pointer) or they can be User Defined (defined by classes)

  #### Encapsulation
  > Separates the interface from the implementation

  ```` // cube.h: ````  Interface/API (What the class is supposed to do)

  ```` // cube.cpp: ```` Implementation (how the class is supposed to do it)

  #### Inclusion Guards
  > "#pragma once" sends a message to the compiler that this file is only included once.
  > "#ifndef CUBE_H_ , #define CUBE_H_, #endif" is the same as above

  ```` // cube.h: ```` Equivalent Implementation
  ``` c++
  #ifndef CUBE_H_ 
  #define CUBE_H_

  class Cube {
    public:
    private:
  };

  #endif 
  ```

  ``` c++
  #pragma once

  class Cube {
    public:
    private:
  };
  ```
  
  #### Scope Resolution Opperator
  > 'double Cube::getVolume(){ . . . }' in Cube.cpp allows us to implement the getVolume() method in the Cube class
  
  </details>

  ### Lecture 2: Classes jan 21 (1/16)
  <details> <summary> <span style="color: green"> Lecture 2 </span></summary>

  #### Public vs Private
  > Public variables are members of classes that can be accessed from the outside of the class

  > Private variables are members of classes that can only be used within the class's functions and cannot be viewed outside the classes

  #### Namespace
  > Namespaces are like Libraries in C++. std = standard namespace includes cout, vector, queue,
  
  ```` cs225::Cube: ```` cs225 namespace includes Cube, PNG, HSLAPixel, etc

  ```` std::cout ```` standard namespace includes cout, vector, queue, etc

  ```` // cube.h declares namespace class Cube````
  ``` c++
  #pragma once 
  namespace cs225 {
    class Cube {
      public:
        double getVolume();
        double getSurfaceArea();
        void setLength(double length);
      private:
        double length_;  
    };
  ```
  ```` // cube.cpp implementation of func in the Cube Class in cs225 namespace ````
  ``` c++
  #include "Cube.h" 
  namespace cs225 {
    double Cube::getVolume() {
      return length_*length_*length_;
    }
    double Cube::getSurfaceArea() {
      return 6 * length_ * length_;
    }
  void Cube::setLength(double length){
      length_ = length;
    
  ```
  ```` // main.cpp using the objects of Cube class ````
  ``` c++
  #include “Cube.h”
  #include <iostream>

  int main() {
      cs225::Cube c; // declares obj of cube type
      std::cout << "Volume: " <<    c.getVolume() << std::endl;
      return 0;
  }
    
  ```

  #### Constructor
  ```` Default Constructor: ```` No parameter, Initializes the class value to default values

  ```` Custom Contructor: ```` user may set the initialization 

  ```` // cube.h ````
  ``` c++
  /* ... */
  class Cube{
    public:
    Cube (); // default constructor
    Cube (double r); // custom constructor
  /* ... */
  ```
  ```` // cube.cpp ````
  ``` c++
  /* ... */

  Cube::Cube() { //define default constructor
      radius_ = 1;
  }
  Cube::Cube(double r) { //define custom constructor
      radius_ = r;
  }
  ```
  ```` // main.cpp ````
  ``` c++
  /* ... */
  main(){
    cs225::Cube c; // initializes/uses automatic Cube constructor w length 1
    cs225::Cube c(5) // initializes/uses custom Cube constructor w length 5
  }
  ```

  #### Reference Variables
  > aliases is used to bound two values together. 
  > once the value of j changes, the value of i changes changes and vice versa

```` main.cpp ````
``` c++
int main {
     int i = 7;

     /* j is an alias of i */
     int &j = i;   	

     /* j and i are both 4 */
     j = 4;		
     std::cout << i << “ ” << j << std::endl;   

     /* j and i are both 2 */
     i = 2;		
     std::cout << i << “ ” << j << std::endl;   
     return 0;
}
```

  </details>

  ### Lecture 3: Memory jan 24 (1/18)
  <details> <summary> <span style="color: green"> Lecture 3 </span></summary>

  #### Variable, Reference Variables, Pointers

  ```` Cube   s1; ```` // a variable containing a Cube obj

  ```` Cube & s2; ```` // a reference to a variable of type Cube

  ```` Cube * s1; ```` // a pointer to a variable of type Cube

  #### Pointers and References
  > a ptr has its own memory addr and size on the run time stack

  > a reference shares the same memory addr (w the original variable) but also takes up its own 'spot' in the run time stack

  ``` c++
  int i = 3;
  int *ptr = &i; // a ptr to variable 'i'. ptr stores addr of i
  int &ref = i;  // a reference (or alias) for i
  ```

  ```` Initialization of a pointer variable ````
  ``` c++
  int  a = 10;
  int *p = &a; // do not do it this way. looks weird becuz p = &a is better

  OR

  int  a = 10;
  int *p;
  p = &a;   // value of 'p' = addr of 1
  print(*p) // prints the dereferenced '*p' value at the addr of &a 
  ```

  > pointers can be re-assigned. 
  ``` c++
  int a = 5;
  int b = 6;
  int *p;
  p =  &a;
  p = &b;
  ```

  ```` Initialization of a reference variable ````
  ``` c++
  int  a = 10;
  int &p = a; // addr of p takes the value of 10
  ```

  > references canNOT be re-assigned: ERROR for MULTIPLE DECLARATION
  ``` c++
  int a = 5;
  int b = 6;
  int &p = a;
  int &p = b; 
  ```

  #### Indirection Operators
  > You can have pointers to pointers offering extra levels of indirection
  ``` c++
  int  a = 10;
  int *p;
  int **q;
  p = &a;   // value of 'p' = addr of a
  q = &p;   // value of 'q' = addr of p

  ```

  > Whereas references only offer one level of indirection
  ``` c++
  int  a = 10;
  int *p;
  p = &a;   // value of 'p' = addr of 1
  &p = a;   // the addr of 'p' = the value of a = the value of 10

  //       val of p   (p) = addr of a
  //       addr of p (&p) = val of a, 10
  // deref val of *p (*p) = val of a, 10
  ```
  
  ```` &c ```` ret the mem addr of c's data 
  
  > '&' operator takes us one step away from the data
  
  ```` *ptr ```` returns the data at the mem addr contained at ptr. 

  > '*' operator takes us one step closer to the data

  #### Stack Memory
  > Starts near top of memory (high addr) -> Data grows downward -> Ends at 0 (low addr)

  > The data is read from low to high (the data is read up).

  #### Stack Frames
  > Think ECE 220
  ```` stack frames ```` are created whenever a function is called and are reclaimed (deleted) when a function returns.
  
  ```` reclaimed stack frames ```` are automatically marked free (not actually freed). When memory is marked free, it can be overwritten. (We never want to return a pointer to a stack variable)


  </details>
  
  ### Lecture 4 : Heap Memory jan 26 (1/23)
  <details> <summary> <span style="color: green"> Lecture 4 </span></summary>

  #### Heap Memory Description
  > Starts near bottom of memory (low addr) -> Data grows upward -> Ends at top of memory (high addr)

  ```` 'new' keyword ```` creates heap memory (returns a ptr to the 'new' memory created)
  > allocates heap mem, calls obj's constructor, and returns a ptr to the memory

  ```` 'delete' keyword ```` frees ('deletes') the heap memory
  > calls obj's destructor, marks mem as freed

  ```` heap1.cpp ````
  ``` c++
  int main() {
     int *p = new int;          //pointer on stack, int on heap
     Cube *c = new Cube(10);    //pointer on stack, object on heap
     delete c;   c = nullptr;   //delete and set null
     delete p;   p = nullptr;
     return 0;
  
  }

  ```
  
  #### Reference Variable
  > aliases is used to bound two values together. 
  > once the value of j changes, the value of i changes changes and vice versa

  ```` reference.cpp ```` // i and j are the same thing, they change together 
  ``` c++
  #include <iostream>

  int main() {
    int i = 7;
    int & j = i;   // j is an alias of i
  
    j = 4;
    std::cout << i << " " << j << std::endl; // output: 4 4

    i = 2;
    std::cout << i << " " << j << std::endl; // output: 2 2

    return 0;
  }

  ```

  #### The use of '&' operator for references
  > A declaration of a reference variable would be like: 

  ```` ALIASES INIT: space in between & and variable name ````
  ``` c++
  int a = 3
  int & b = a;        //declaring a reference variable  

  ```

  > this process should not be confused with the case of getting the memory address of a variable which would also involved with '&' operator, as the example shown below:
  
  ```` REFERENCE INIT: no space in between & and variable name ````
  ``` c++
  Cube c;
  std::cout << "Mem address storing c: " << &c << std::endl;

  ```

  #### 

  </details>

  ### Lecture 5 : Function & Parameter jan 28 (1/25)
  <details> <summary> <span style="color: green"> Lecture 5 </span></summary>

  #### Function Parameters
  > There are 3 ways to pass an arguement to a function

  ##### pass by value 
  the obj passed in it a copy of the original obj. By changing it, we do not change the original. Less efficient because it needs extra memory

  ```` joinCubes-byValue.cpp ````

  ``` c++
  Cube joinCubes(Cube c1, Cube c2) {
    double totalVolume = c1.getVolume() + c2.getVolume();
    ...
    Cube result(newLength);
    return result;
  }

  int main() {
    Cube *c1 = new Cube(4);
    Cube *c2 = new Cube(5);
    Cube c3 = joinCubes(*c1, *c2); 
    return 0;
  }

  ```

  ##### pass by pointer
  the obj passed in is a pointer of the original obj. By changing it, we do change the original. More efficient because we treat the memory. But more risky because we can get an invalid paramter (NULL) that gets passed in

  ```` joinCubes-byPointer.cpp ````
  ``` c++
  Cube joinCubes(Cube * c1, Cube * c2) {
    double totalVolume = c1->getVolume() + c2->getVolume();
    ...
  }
  int main() {
    Cube *c1 = new Cube(4);
    Cube *c2 = new Cube(5);
    Cube c3 = joinCubes(c1, c2); 
    return 0;
  }
  ```


  ##### pass by reference
  the obj passed in is an alias of the original obj. By changing it, we do change the original. More efficient because we treat the memory. But more risky because we are changing the original value

  ```` joinCubes-byRef.cpp ````

  ``` c++
  Cube joinCubes(Cube & c1, Cube & c2) {
    double totalVolume = c1.getVolume() + c2.getVolume();
    ...
  }

  int main() {
    Cube *c1 = new Cube(4);
    Cube *c2 = new Cube(5);
    Cube c3 = joinCubes(*c1, *c2); 
    return 0;
  }

  ```

  #### Summary
  | --- | Pass By Value | Pass By Pointer | Pass By Reference |
  | --- | --- | --- | --- |
  | The copied content| The entire data | the memory addr | just an alias |
  | Does the modification go through the caller's obj | No | Yes | Yes |
  | Always Valid when passed in | Yes | No - could be NULL when passed in | Yes |
  | Relative speed among 3 ways to pass func parameters | Slow (depending on data size) | Fast (always 8 bytes) | Fast |
  | The Relative Programming Safety | Safety | Not Safe | Safe-ish |

  #### The 'const' Function Parameter
  The keyword 'const' is a way to prevent the parameters passed in to be changed. We are saving the memory because we are not passing by value and at the same time to avoid the risk of changing the original. 

  ```` joinCubes-byRef-const.cpp ````

  ``` c++
  Cube joinCubes(const Cube & c1 , const Cube & c2) {
    double totalVolume = c1.getVolume() + c2.getVolume();
    ...
  }
  int main() {
    ...
    Cube c3 = joinCubes(*c1, *c2);
    return 0; 
  }

  ```

  </details>

  ### Lecture 6 : LifeCycle & Constructors jan 31 (1/28)
  <details> <summary> <span style="color: green"> Lecture 6 </span></summary>

  #### Copy Constructors
  ```` Automatic Copy Constructors ```` Generated if we don't define a copy const, Copies every instance variable in the obj

  ```` Custom Copy Constructor ```` passed by reference

  ``` c++
  Cube(const Cube & other){
    ...
  };

  ```
  
  #### Calls to Copy Constructor

  | Constructors | joinCube(Cube c1, Cube c2) {...} BY VALUE | joinCube(Cube * c1, Cube * c2) {...} BY POINTER | joinCube(Cube & c1, Cube & c2) {...} BY REFERENCE |
  | --- | --- | --- | --- | 
  | Cube(); | 0 | 0 | 0 |
  | Cube(double length); | Cube result(newLength) | Cube result(newLength) | Cube result(newLength) |
  | Cube(Cube & other); //COPY CONSTRUCTOR | joinCube(Cube c1, Cube c2); return result; | return result; | return result |

  > the copy constructo is called when the parameter is passed-in (and when the reslt is returned)

  ```` joinCubes-byValue.cpp ````
  ``` c++
  Cube joinCubes(Cube c1, Cube c2) {
    double totalVolume = c1.getVolume() + c2.getVolume();
    ...
    Cube result(newLength);
    return result; // 000
  }

  ```

  #### Copy Constructor Initializer
  > it tells the compiler to 'shallow' copy instance variables to the variables in "other"

  ```` Tower.h ````
  ``` c++
  #pragma once
  #include "cs225/Cube.h"
  using cs225::Cube;
  class Tower {
    public:
      Tower(Cube c, Cube *ptr, const Cube &ref); 
                            // Custom constructor 
      Tower(const Tower & other); 
                            // Copy constructor

    private:
      Cube cube_;
      Cube *ptr_;
      const Cube &ref;
  };

  ```

  ```` Tower.cpp: Automatic Copy Constructor which makes a copy of every variable ````
  ``` c++
  Tower::Tower(const Tower & other) : cube_(other.cube_), ptr_(other.ptr_), ref_(other.ref_) {
    //every variable copied
    //nothing needed in the body
  }

  ```

  #### Deep Copy Constructor
  > a deep copy initializes the constructed variable in memory

  > deep copies are used for every instance variable (specifically the pointer, we want a new Cube)

  ```` Tower.cpp ````
  ``` c++
  Tower::Tower(const Tower & other) : ref_(other.ref_){
    
    // Deep copy cube_:  using other
    cube_ = other.cube_;

    // Deep copy ptr_
    ptr_ = new Cube`(*other.ptr_);

    // Deep copy ref_ (?)
      // Doesn’t make sense to “deep copy” an alias
      // Done in the Initializer List
  }

  ```

  #### Deconstructor
  > used to clean up all resources (memory) held by the class. This is done by cleaning up heap memory and closing all of the files

  // for all ```` new ```` memory being created, we must free the memory by using ```` delete ```` so that they dont leak

  > leaked memory means that the memory was created (never destroyed). In other words, we filled the memory (flooded) with memory that will no longer be used or usable... thus it is a leak of used memory that can no longer be used by something else in the function call

  #### Custom Deconstructor
  > if the member variables are initiated on a hea, we must define a custom deconstructor

  ```` cube.h ````
  ``` c++
  #pragma once

  namespace cs225 {
    class Cube {
      public:
        Cube();  Cube();
        Cube(double length);
        Cube(const Cube & other); 
        ~Cube(); // used as a custom deconstructor in order to free heap 'new' memory


      private:
        double length_; 
    };
  }

  ```

  ```` cube.cpp ````
  ``` c++
  namespace cs225 {
  Cube::Cube() {
    length_ = 1;
  }

  Cube::Cube(double length) {
    length_ = length;
  }

  Cube::Cube(const Cube & other) {
    length_ = other.length_;
   }

  Cube::~Cube() {
   …..//define your destructor HERE
   delete length_;
  }
}

  ```

  #### Automatic Destructor
  > if no other de-constructor is defined, then an automatic destructor is instantiated. It calls the destructor of the members w/out doing anything else

  // stack memory is reclaimed (cleared) and now usable again

  // heap memory is 'deleted' and now usable again

  </details>


  ### Lecture 7 : Overloading and Inheritance feb 2 (1/30)
  <details> <summary> <span style="color: green"> Lecture 7 </span></summary>

  #### Overload operators in cpp
  > we use the example of overloading the "+" and "=" operator

  ```` cube.h: Initialize the operation overloads of '+' and '=' ````
  ``` c++
  Cube operator+(const Cube & other) const;
  Cube & operator=(const Cube & other);
  /*Ex: Cube a,b,c;
  C = a+b
  The const inside () means do not modify b
  The const after () means do not modify a
  */

  ```

  ```` cube.cpp: implement each of the overloads for '+' and '=' ````
  > (1) given that the '+' operator in math reads from left to right. we must use the hot variable 'this' to represent the left object and use 'other' to represent the right object when we use the overloaded '+' operator, we essentially take the left (*this) and right (other) objects and "join" them togerther using the joinCube function

  > (2) given that '=' needs to return an object type Cube, we must look at the '=' symbol as a sort of deep copy constructor. If we look at it as a deep copy constructor, we can see that the 'other' (obj directly to the right of the '=') will to passed in. The output of the deep copy constructor will be the a new Cube that has a new length of the cube that was passed in. when we see 'c3 = c1 + c2' the operation reads "set the c3 (Cube obj) to a new Cube that is the joined version of c2 (*this)(Cube Obj) and c1 (other)(Cube Obj)." NOW if we were to do 'c3 = c2' what we will be saying is "set the c3 (Cube obj) to a new Cube that is c2 (Cube Obj). 
  ``` c++
  // READ COMMENT (1) above
  Cube Cube::operator+(const Cube & other) const {
    return joinCube(*this, other);
  }

  // READ COMMENT (2) above
  Cube & Cube::operator=(const Cube & other) {
    length_ = other.length_; 
    return *this;
  }
  ```
  
  ##### Defining "+" operator
  > if we were to do "Cube cube3 = cube1 + cube2" we must overload the '+' operator to essentially take the left and right values of the + and joing them. 
  
  ```` IMPORTANT: ```` one thing to note about the overloading the assignment operator is that we are essentially creating a new copy of what ever is being passed in on the right side of the '=' symbol. Thus, there will 99% of the time be a case where the left (*this) and right (other) are different. In that 99% chance, we will want to destroy (or delete) the memory of the 'old' left side to free up that memory and replace that memory (set it to) with the 'new' right hand side object. 

  ##### Assignment "=" operator
  > look at it as a copy constructor. ESSENTIALLY, this operation overload of the '=' allows us to "RE-USE" the '=' symbol for the purposes other than numbers, chars, and primary variable types. We can essentially run operations on a variable of any type that is not a primary variable type (in this case, a Cube Obj type) and set the thing on the left (*this) to the return variable on the right (other) as long as they are the same variable type

  ``` c++
  Cube & Cube::operator=(const Cube & other){
    if (this != &other) { //If I’m not copying myself
      _destroy();
      _copy(other);
    }
    return *this;
  };

  ```


  #### Rule of Three
  > for every time that an operation overload is needed, you must define all of the below

  - assignment operator
  - copy constructor
    - use ' if (this == &other) { return *this; } in order to prevent from copying itself
  - destructor


  #### Inheritance
  > Classes cna be used to extend the build of other classes. Inheritance describes the extension of the base class to the derived class (the inheriting class). In the case below, everything in shpae public is now part of and derived in the square public. (NO PRIVATE VARIABLES WERE INHERITED FROM SHAPE)

  ```` square.h ````
  ``` c++
  #pragma once
  #include "Shape.h"
  class Square : public Shape {
  //syntax of inherit
    public:
      Square();
      Square(double length);
      double getArea() const;
  private: };
  ```

  ```` square.cpp ````
  ``` c++
  Square::Square() { }
  Square::Square(double length) : Shape(length) { }

  double Square::getArea()
  const {
    return getLength() * getLength();
  }

  ```
  </details>

  ### Lecture 8 : Inheritance & Templates feb 4 (2/1)
  <details> <summary> <span style="color: green"> Lecture 8 </span></summary>

  #### Virtual functions
  > the purpose of a virtual function is to override the function of the base class with the a more 'specified' function that will be used in the derived class. If you would like for a function in a base class to be completely overwritten by all of its child (derived class) functions, then you may want to implement a 'pure virtual' function, which means that the entirety of that function is going to be written by the derived function and that for every derived class you create, you must implement that purely virtual function in order to make it specific to the derived class. 
  ```` cube.cpp (general cube)````
  ``` c++
  Cube::print_1() {
  cout << "Cube" << endl;
  }
  Cube::print_2() {
    cout << "Cube" << endl;
  }
  virtual Cube::print_3() { 
    cout << "Cube" << endl;
  }
  virtual Cube::print_4() {
    cout << "Cube" << endl;
  }
  // In .h file:
  virtual print_5() = 0; // pure virtual function
  ```

  ```` RubiksCube.cpp (a specific type of cube) ````
  ``` c++
  // No print_1() in
  RubikCube.cpp 

  RubikCube::print_2() { 
    cout << "Rubik" << endl;
  }

  // No print_3() in
  RubikCube.cpp

  RubikCube::print_4() {
    cout << "Rubik" << endl;
  }

  RubikCube::print_5() {
    cout << "Rubik" << endl;
  }
  ```

  #### Pure virtual functions

  #### Abstract Classes
  - one or more pure virtual functions
  - cannot create an instance of an abstract class... must create an instance of the derived class Cube c1 (no good), RubiksCube rc1 (good)

  #### Virtual Destructor

  #### Abstract Data Type (ADT)
  > given that we are able to do basic operations on types of data (overloading symbols to accomodate for new types of objs, virtual functions to accomodate for making general obj types/class more specific), we can essentially create any abstract data type (ADT). Creating an ADT allows us to change the functionality of a type of data. In other words, overloading symbols allows us to do primal operations on the new type of data that we want to create &&& making class functions and classes virtual allows us to create specific variations of the same type of data (child inherits from the parent) (derived inherits from the base)

  #### Templates: a dynamic data type
  > given that we are able to create various types of data (ADTs). we can create functions that allows us 'template' a function for any given data type. given any number of data types (abstract and not abstract) we can create a templated function that can do the same function but for all those data types. As long as the return types are consistent, and the variables of the passed in templated function fit the needs for all ADTs, we can utilize a template function to accomodate the same operation for any data type. 


  </details>

  ### Lecture 9 : Templates and List Abstract Data Types (ADT) feb 7 (2/4)
  <details> <summary> <span style="color: green"> Lecture 9 </span></summary>

  ^^^ idk why they slow. but ```` Abstract Class ```` ```` Virtual Destructor ```` ```` Abstract Data Type (ADT) ```` and ```` Templates: used for dynamic data types ```` are all above

  #### Types of Implementation of a List
  
  ``` c++
  template <typename T>
  T maximum(T a, T b) {
      T result;
      result = (a > b) ? a : b;
      return result;
  }

  ```

  ##### Array
  > Common Array. It is a sequential block of items, a list with a set number of memory blocks that can be filled

  ##### Linked Memory
  > More commonly known as a linked list. Linked Memory generally has two attributes (variables) that are instantiated in the List Class that you are about to create: node pointer that points to the next block of memory (ListNode *next) and the data that is stored in that particular memory block (T * data)

  ```` List.h ````
  ``` c++
  #ifndef LIST_H
  #define LIST_H

  template <typename T>
  class List {
      public:
            /* ... */
      private:
          class ListNode {
                T & data;
                ListNode * next;
                ListNode(T & data) : data(data),
  next(NULL) { }
          };
  }; 
  
  #endif
  ```

  More on List function implementations are made in the next lecture

  </details>

  ### Lecture 10 : List Implementations feb 9 (2/6)
  <details> <summary> <span style="color: green"> Lecture 10 </span></summary>
  > for now, we know how to initialize a linkedlist and its basic variables that make it a linkedlist (particularly a singly linked list). In this section, we will go over how to implement the following functions that will help us do operations to the linkedlist

  #### Inserting Node at Front of the LinkedList
  1. initialize some memory in the heap for a 'new' object of type ListNode with data 't' 
  2. set the new ListNode's 'next' to the current head of the LinkedList
  3. set the list's head to the new ListNode
  > always set the new ListNode's next (later you will deal with prev) to the location before changing the location  of the old node
  ```` .cpp file ````
  ``` c++
  template <typename T>
  void List<T>::insertAtFront(T & t, unsigned index) {
      ListNode * node = new ListNode(t);
      node->next = head_;
      head_ = node;
  }
  ```

  #### Finding an Element in the LinkedList at the 'index' spot
  0. first we have to realize that the return type of this function (_index) is a *&, which means that we will have a ```` pointer to a location ````
  1. check if index == 0. if index = 0, return the head of the LinkedList. else, move on
  2. initialize a pointer to the head 'thru' or 'iter' (the start of the linked list) 
  3. iterate the 'index' number of times through that list by setting the pointer to the point to the next node 
  4. once the pointer 'thru' has iterated through the list a total of 'index' times, return the 'next' node which is the ```` pointer to the location ```` of the node that we are trying to return

  ```` .cpp file ````
  ``` c++
  // Iterative Solution:
  template <typename T>
  typename List<T>::ListNode *& List<T>::_index(unsigned index) {
  //return a reference to a ListNode pointer
  
    if (index == 0) {
      return head;
    } else {
      ListNode *thru = head;
      for (unsigned i = 0; i < index - 1; i++) {
        thru = thru->next;
      }
      return thru->next;

    }
  }
  ```
  > the reason why we return the thru->next is because we are trying to return the point to the location of the node... not the actual node itself. 

  #### Overloading the [] operator
  > we can make the linkedlist behave like an array by overloading the "[]" symbols. We will want to return the data of within the node, not a pointer to the location of the data. We re-use the _index() function in order to access the pointer to the location. Now we will want to take the data at that location, so the '&' will allow us to 
  
  0. first we must realize that the return type of this operation overload is a &, which means that we will have a ```` location ````
  1. initialize a ListNode ```` pointer to a location ```` and index through the linked list the same way we would index and access the data element in an array. 'd' will now be pointing to the location of the index
  2. return the data at that indexed element in the linked list (return the data at the location of that index)

  ```` List.hpp ````
  ``` c++
  template <typename T>
  T & List<T>::operator[](unsigned index) {
    ListNode *& d = _index(index);
    return d -> data;
  }
  ```


  #### Inserting a Node in the middle of the LinkedList
  0. we must first realize that the return type of this function is a void. This is because we will not be outputting anything, we will be doing an operation on a linked list and that is it
  1. initialize a ListNode 'node' ```` pointer to a location ```` which will index through the linkedlist the same way we found an element at a given index. node is returned as a pointer to the location of the indexed element of the linkedlist
  2. now we initialize a new ListNode in the Heap memory with the data set to 't'. Notice that the type of variable newNode is a pointer. We want the newNode to be a pointer because it holds the data as 't' and has to have the other attribute of a pointer to the next value
  3. we set the newNode's next to the node that we indexed
  4. then we set the old node to be the newNode the same way we inserted a ListNode at the front of the LinkedList
  > SIMILAR TO INSERTING NODE AT FRONT: always set the new ListNode's next (later you will deal with prev) to the location before changing the location of the old node

  ```` List.hpp ````
  ``` c++
  template <typename T>
  void List<T>::insert(const T & t, unsigned index) {
    ListNode *& node = _index(index);
    ListNode * newNode = new ListNode(t);
    newNode -> next = node;
    node = newNode;
  }
  ```

  #### Removing a Node from the LinkedList
  0. realize that the return type of this function is a location. We do this because
  1. initialize a ListNode 'node' ```` pointer to a location ```` which will index through the linkedlist the same way we found an element at a given index. node is returned as a pointer to the location of the indexed element of the linkedlist
  2. now we initialize a temporary 
  3. 
  4. 
  5. 
  6. 
  > 

  ```` ````
  ``` c++
  template <typename T>
  T & List<T>::remove(unsigned index) {
    ListNode *& node = _index(index);
    ListNode * temp = node;
    T & data = node -> data;
    node = node -> next;
    delete temp;
    return data;
  }
  ```

  
  </details>

  ### Pit Stop: Big O Notation
  <details> <summary> <span style="color: green"> Big O Notation </span></summary>
  ```` Definition: ````
  > 

  ```` How to Calculate Big O: ````
  > 

  | O(x) | Description | Common Algorithms with this Time Complexity | Common algorithms with this Space Complexity |
  | --- | --- | --- | --- |
  | O(log(n)) | --- | --- | --- |
  | O(1) |  |  |  |
  | O(k) |  |  |  |
  | O(n) |  |  |  |
  | O(n^2) |  |  |  |
  | O(n^k) |  |  |  |
  | O(k^n) |  |  |  |
  </details>


  ### Lecture 11 : Lists feb 11 (2/8)
  <details> <summary> <span style="color: green"> Lecture 11 </span></summary>
  
  #### Different Implementations of a List
  > There are arrays and singly linked lists.
  ```` ArrayLists: ```` sequential blocks of memory where one element follows immediately after the other
  ```` Singly Linked Lists: ```` same as array, but sequentially linked via pointer to the next (or prev) elem

  ##### Singly Linked Lists
  > 

  ```` List.h ````
  ``` c++
  #ifndef LIST_H
  #define LIST_H

  template <typename T>
  class List {
      public:
            /* ... */
      private:
          class ListNode {
                T & data;
                ListNode * next;
                ListNode(T & data) : data(data),
  next(NULL) { }
          };
  }; 
  
  #endif
  ```
  ##### Array List
  - has a mamimum size
  - you can directly point into the array elem

  ```` ArrayList.h ````
  ``` c++
  #pragma once
  template <typename T>
  class List {
    public:
      /* ... */
    private:
      T * arr_;      // the content array
      int capacity;  // the maximum size possible;
                        the allocated array size
      int count;     // the size in use; the number
                        of current elements
  };
  ```



  ##### Insert/Remove at Front

  ```` LinkedList Method [O(1)]: ```` 
  > only one iteration
  1. init new ListNode
  2. set new ListNode-> next to list's head
  3. set head to new ListNode

  ```` ArrayList Method  [O(1)]:````
  > method 1 O(n): every time we run out of space, we create a new_array and copy all of the n elems from old_array to the new one, thus O(n) in space
  1. create a new_array of length old_length + 1
  2. set 0th elem to new head
  3. copy the old_array into new array

  > method 2 O(1): ONLY 1 element is being added. THERE IS NO Copying of old arrays into a new array that occurs in this method
  1. in addition to the old array, keep the old array and ADD a new_array of length old_length
  2. set 0th elem to new 0th elem
  2. THERE IS NO NEED TO copy the old_array into new array since we will just be adding a new array of length old_array and then just inserting the elem into that array

  ##### Insert afterat a given element

  ```` LinkedList Method [O(1)]: ````

  ```` ArrayList Method  [O(n)]:````

  ##### Remove after a given element

  ```` LinkedList Method [O(1)]: ````

  ```` ArrayList Method  [O(n)]:````

  ##### Insert a n arbitrary element

  ```` LinkedList Method [O(n)]: ````

  ```` ArrayList Method  [O(n)]:````

  ##### Remove at an arbitrary location

  ```` LinkedList Method [O(n)]: ````

  ```` ArrayList Method  [O(n)]:````

  
  #### LinkedList vs ArrayList
  | --- | Singly Linked Lists | ArrayList |
  | --- | --- | --- |
  | Insert/Remove at Front | O(1) | O(1) |
  | Insert afterat a given element | O(1) | O(n) |
  | Remove after a given element | O(1) | O(n) |
  | Insert a n arbitrary element | O(n) | O(n) | 
  | Remove at an arbitrary location |  O(n) | O(n) |

  #### std::vector
  > very much like an array, but without a capacity on the number of elements
  > an insert will take O(n) at most
  > 'push_back' functino takes O(1) since it adds to the end of the array

  </details>

  #### Stack ADT

  #### Queue ADT

  ### Lecture 12 : Lists, Stacks and Queues feb 14 (2/11)
  <details> <summary> <span style="color: green"> Lecture 12 </span></summary>
  
  ```` IDK. I THINK I MIGHT HAVE SKIPPED SOMETHING ````
  </details>

  ### Lecture 13 : Iterators feb 16 (2/11)
  <details> <summary> <span style="color: green"> Lecture 13 </span></summary>
  
  #### Queue Implementation


  #### Three Data Storage Strategies


  #### Tradeoffs about Three Data Storages


  #### Iterators for storages


  </details>


  ### Lecture 15 : Tree Intro feb 18 (2/13)
  <details> <summary> <span style="color: green"> Lecture 15 </span></summary>
  
  #### Trees

  #### Binary Trees

  
  </details>

  ### Lecture 16 : Trees feb 21 (2/15)
  <details> <summary> <span style="color: green"> Lecture 16 </span></summary>
  
  #### Tree Terminology Review

  #### Binary Tree

  #### Computation of Tree Height

  #### Full Tree

  #### Perfect Tree

  #### Complete Tree

  #### Tree Property

  #### Tree Abstract Data Type

  </details>

  ### Lecture 17 : Tree Traversals feb 23 (2/18)
  <details> <summary> <span style="color: green"> Lecture 17 </span></summary>

  #### Number of NULL Pointers in a Binary Tree

  #### Traversals 

  ```` Pre-Order ````
  ```` In-Order ````
  ```` Post-Order ````
  #### In-Order Print out of the Tree

  #### Level Order Traversal
  </details>

  ### Lecture 18 : BST feb 25 (2/20)
  <details> <summary> <span style="color: green"> Lecture 18 </span></summary>
  
  #### Traversal vs Search
  
  #### BFS ()
  
  #### DFS ()  
  
  #### Running Time
  
  #### Dictionary ADT
    
  #### BST   
  
  #### Find Function in BST
  
  #### Insert in BST

  </details>
  
  ### Lecture 19 : BST Remove feb 28 (2/22)
  <details> <summary> <span style="color: green"> Lecture 19 </span></summary>
    
  #### Remove in BST
  
  #### Relationship between H and N
  
  #### Proof of Induction
  
  </details>

  ### Lecture 20 : BST Balance mar 2 (2/25)
  <details> <summary> <span style="color: green"> Lecture 20 </span></summary>
  
  ####   Height of BST
  
  ####   Height Balanced-Tree
  
  ####  Lowest Point of Imbalance

  ####  BST Rotation



  </details>


  ### Lecture 21 : AVL mar 4 (2/27)
  <details> <summary> <span style="color: green"> Lecture 21 </span></summary>
  
  #### Four BST Rotation
  

  #### AVL Tree Consideration

   
  #### Rotations Thereom #1
  

  #### Rotations Thereom #2
      

  #### Insertion of AVL
  
   

  </details>


  ### Lecture 22 : AVL Analysis mar 7 (3/1)
  <details> <summary> <span style="color: green"> Lecture 22 </span></summary>
    
  #### AVL Remove
  

  #### AVL Summary

   
  #### BIG-O Definition
  

  #### AVL Tree Theorem
   
   
  </details>

  ### Lecture 23 : AVL Applications mar 9 (3/4)
  <details> <summary> <span style="color: green"> Lecture 23 </span></summary>

  #### AVL Summary


  #### Red-Black Tree


  #### Advantage of AVL (os Balanced BSTs in general)


  #### Disadvantages of AVL (or Balances BSTs in general)


  #### Standard Map in C++


  #### Summary of Everyon Data Structure so far


  #### Range based Searching

  
  </details>

  ### Lecture 24 : B-Trees + B Tree Analysis mar 11 (3/11)
  <details> <summary> <span style="color: green"> Lecture 24 </span></summary>
  
  #### B-Tree Motivation


  #### B-Tree (of order m)


  #### B-Tree Structure


  #### B-Tree Properties


  #### Determining the Order of a B-Tree 


  #### B-Tree Search




  
  </details>

  ### Lecture 25 : B-Tree Analysis mar 21 (3/11)
  <details> <summary> <span style="color: green"> Lecture 25 </span></summary>
  
  #### B-Tree Analysis


  #### BTree: Minimum number of keys in a BTree of height h and order m:


  #### BTree_ Min Total Nodes


  #### BTree: Min Total Keys


  #### BTree: Max Total Keys


  </details>

  ### Lecture 26 : Hashing pt 1 mar 23 (mar 13)
  <details> <summary> <span style="color: green"> Lecture 26 </span></summary>
  
  #### Hashing Introduction


  #### Keyspace


  #### 


  #### A good HASH Function should:

  
  </details>

  ### Lecture 27 : Hashing pt 2 mar 25 (3/15)
  <details> <summary> <span style="color: green"> Lecture 27 </span></summary>
  
  #### Collision


  #### Seperate Chaining


  #### Linear Probing


  
  </details>

  ### Lecture 28 : Hashing pt 3 mar 28 (3/15)
  <details> <summary> <span style="color: green"> Lecture 28 </span></summary>
  
  #### Primary Clustering


  #### Double Hashing


  #### Running Time
    
  </details>

  ### Lecture 29 : Heaps mar 30 (3/27)
  <details> <summary> <span style="color: green"> Lecture 29 </span></summary>
  
  #### The Priority Queue/Heap


  #### Implementations


  #### Tree Structure Implementation: The (min)Heap


  #### Insertion


  #### Remove

  
  </details>

  ### Lecture 30 : Heaps and Disjoint Sets apr 1 (3/27)
  <details> <summary> <span style="color: green"> Lecture 30 </span></summary>
  
  #### NOTHING. COMBINED WITH PREV


  
  </details>
  
  ### Lecture 31 : Disjoint Sets apr 4 (4/1)
  <details> <summary> <span style="color: green"> Lecture 31 </span></summary>
  
  #### Build Heap Runtime


  #### Theorem: BuildHeap based on heapify-down takes O(n) time


  #### HeapSort


  #### Disjoint Sets


  #### Disjoint Sets ADT


  #### Implementation #1


  #### Union (k1, k2)

  
  </details>
  
  ### Lecture 32 : Graphs apr 6 (4/5)
  <details> <summary> <span style="color: green"> Lecture 32 </span></summary>
  
  #### Disjoint Set Find


  #### Smart Unions


  #### Union by Size


  #### Root== -n


  #### Union by Rank


  #### Union by Size


  #### Path Compression


  #### Running Time with Path Compression


  #### Panorama of Data Structures

  ##### Array Based (Cache-optimized)

  ##### List/Pointer Based


  #### Graphs


  #### Graph Vocabulary
  - verticies
  - edges
  - incident edges
  - degress
  - adjacent vertex
  - path
  - cycle
  - simple graph

  #### 

  
  </details>
  
  ### Lecture 33 : Graph Implementations apr 8 (4/8)
  <details> <summary> <span style="color: green"> Lecture 33 </span></summary>
  
  #### Continued Graph Vocabulary 
  - Sub Graph
  - Complete Sub graph
  - Connected Sub graph
  - Connected Component
  - Acyclic Sub graphs
  - spanning trees
  - Minimal Number of Edges
  - Maximal number of edges
  - Sum of all degrees of all vertices = 2*m
  - Theorem: Lemm1
  - Proof
  -- Base Case
  -- Inductive Hypothesis
  --- Suppose
  --- Partition
  --- Count Edges

  #### Graph ADT
  -- Data
  -- Functions

  #### Graph Implementations #1 : Edge Lists
  -- Vertex Collections
  -- Edge Collections
  -- Running Time
  --- Insert Vertex
  --- Remove Vertex
  --- areAdjacent
  --- insertEdge
  --- incidentEdges


  
  </details>

  ### Lecture 34 : Graph Implementations and Traversals apr 11 (4/10)
  <details> <summary> <span style="color: green"> Lecture 34 </span></summary>
  
  #### Graph ADT


  #### Graph Implementation 1: Edge List


  #### Graph Implementation 2 : Adjacency Matrix


  ##### Insert data into the matrix


  ##### Remove a vertex

  
  </details>
  
  ### Lecture 35 : Traversals (nov 10)
  <details> <summary> <span style="color: green"> Lecture 35 </span></summary>
  
  #### Graph ADT


  #### Question: Implementation 2 runs in either O(1) or O(n), while Implementation 1 runs in either O(1) or O(m). Which one is better?


  #### Graph Implementation 3 : ADJ List


  #### 

  
  </details>
  
  ### Lecture 36 : Graph Traversal DFS and Minimum Spanning Tree (nov 12)
  <details> <summary> <span style="color: green"> Lecture 36 </span></summary>
  
  #### 


  #### 


  #### 


  #### 

  
  </details>

  ### Lecture 37 : Minimum Spanning Tree (MST) pt 1 (nov 15)
  <details> <summary> <span style="color: green"> Lecture 37 </span></summary>
  
  #### 


  #### 


  #### 


  #### 

  
  </details>
  
  ### Lecture 38 : Minimum Spanning Tree (MST) pt 2 (nov 17)
  <details> <summary> <span style="color: green"> Lecture 38 </span></summary>
  
  #### 


  #### 


  #### 


  #### 

  
  </details>
  
  ### Lecture 39 : Minimum Spanning Tree (MST) pt 3 (nov 19)
  <details> <summary> <span style="color: green"> Lecture 39 </span></summary>
  
  #### 


  #### 


  #### 


  #### 

  
  </details>

  ### Lecture 40 : End of MST and Single Source Shortest Path (SSSP) (nov 29)
  <details> <summary> <span style="color: green"> Lecture 40 </span></summary>
  
  #### 


  #### 


  #### 


  #### 

  
  </details>


  ### Lecture 41 : All Pairs Shortest Path (APSP) (dec 01)
  <details> <summary> <span style="color: green"> Lecture 41 </span></summary>
  
  #### 


  #### 


  #### 


  #### 

  
  </details>

  ### Lecture 42 : Summary (dec 03)
  <details> <summary> <span style="color: green"> Lecture 42 </span></summary>
  
  #### 


  #### 


  #### 


  #### 

  
  </details>

  ### Lecture 43 : Max Flow (dec 06)
  <details> <summary> <span style="color: green"> Lecture 43 </span></summary>
  
  #### 


  #### 


  #### 


  #### 

  
  </details>

  ### Lecture 44 : Review (dec 08)
  <details> <summary> <span style="color: green"> Lecture 44 </span></summary>
  
  #### 


  #### 


  #### 


  #### 

  
  </details>
  
  ### CONGRATS YOU HAVE FINISHED CS 225 LECTURES
  > Message from Author. I would like to first give credit to all of the Professor, TAs and UAs at UIUC CS255 for all of the notes and lectures




</details>



# Weekly Practice: Labs
Below are all the information about the changes I made on the labs

## Labs: 
<details>
	<summary> Click for ALL LABS </summary>

  ### Setup, Command Line on Linux EWS, etc
  <details> <summary> <span style="color: green"> Setup, Command Line on Linux EWS </span></summary>
  </details>  

  ### lab_intro
  <details> <summary> <span style="color: green"> lab_intro </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_debug
  <details> <summary> <span style="color: green"> lab_debug </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_memory
  <details> <summary> <span style="color: green"> lab_memory </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_inheritance
  <details> <summary> <span style="color: green"> lab_inheritance </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_quacks
  <details> <summary> <span style="color: green"> lab_quacks </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_trees
  <details> <summary> <span style="color: green"> lab_trees </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_huffman
  <details> <summary> <span style="color: green"> lab_huffman </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_avl
  <details> <summary> <span style="color: green"> lab_avl </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_btree
  <details> <summary> <span style="color: green"> lab_btree </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_hash
  <details> <summary> <span style="color: green"> lab_hash </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_heaps
  <details> <summary> <span style="color: green"> lab_heaps </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### lab_dict
  <details> <summary> <span style="color: green"> lab_dict </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>
</details>


# Tri-Weekly Practice: Machine Problems (MPs)
Below are all the information about the changes I made on the Machine Problems

## Machine Problems: 
<details>
	<summary> Click for ALL MACHINE PROBLEMS </summary>

  ### mp_intro
  <details> <summary> <span style="color: green"> mp_intro </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### mp_stickers
  <details> <summary> <span style="color: green"> mp_stickers </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### mp_lists
  <details> <summary> <span style="color: green"> mp_lists </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### mp_traversals
  <details> <summary> <span style="color: green"> mp_traversals </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### mp_mosaics
  <details> <summary> <span style="color: green"> mp_mosaics </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

  ### mp_mazes
  <details> <summary> <span style="color: green"> mp_mazes </span></summary>

  #### Description
  > 'replace with lab concept' 

  #### Changed Files: 
  ```` file1 ```` ```` file2 ```` ```` file3````

  #### Instructions
  ```` file1: ```` 
  
  ```` file2: ```` 
  
  ```` file3: ````

  #### Output Files, Design Statistics and Resources (inspired by ECE 385)
  ```` 'image' of output: ````

  ```` 'image' of terminal (Design Stats & Resources) ````
  
  </details>

</details>