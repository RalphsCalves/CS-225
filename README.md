# CS-225
Data Structures. Enjoy these labs and mps, and please do not pull an all nighter for the labs.

# Understanding Data Structures: Lectures
Below are the notes that I took for Data Structures @UIUC.

## Lectures:
<details> <summary> Click for ALL NOTES </summary>
  
  ### Lecture 1: Introduction
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
  ```
  #ifndef CUBE_H_ 
  #define CUBE_H_

  class Cube {
    public:
    private:
  };

  #endif 
  ```

  ```
  #pragma once

  class Cube {
    public:
    private:
  };
  ```
  
  #### Scope Resolution Opperator
  > 'double Cube::getVolume(){ . . . }' in Cube.cpp allows us to implement the getVolume() method in the Cube class
  
  </details>

  ### Lecture 2: Classes
  <details> <summary> <span style="color: green"> Lecture 2 </span></summary>

  #### Public vs Private
  > Public variables are members of classes that can be accessed from the outside of the class

  > Private variables are members of classes that can only be used within the class's functions and cannot be viewed outside the classes

  #### Namespace
  > Namespaces are like Libraries in C++. std = standard namespace includes cout, vector, queue,
  
  ```` cs225::Cube: ```` cs225 namespace includes Cube, PNG, HSLAPixel, etc

  ```` std::cout ```` standard namespace includes cout, vector, queue, etc

  ```` // cube.h declares namespace class Cube````
  ```
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
  ```
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
  ```
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
  ```
  /* ... */
  class Cube{
    public:
    Cube (); // default constructor
    Cube (double r); // custom constructor
  /* ... */
  ```
  ```` // cube.cpp ````
  ```
  /* ... */

  Cube::Cube() { //define default constructor
      radius_ = 1;
  }
  Cube::Cube(double r) { //define custom constructor
      radius_ = r;
  }
  ```
  ```` // main.cpp ````
  ```
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
```
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

  ### Lecture 3: Memory
  <details> <summary> <span style="color: green"> Lecture 3 </span></summary>

  #### Variable, Reference Variables, Pointers

  ```` Cube   s1; ```` // a variable containing a Cube obj

  ```` Cube & s2; ```` // a reference to a variable of type Cube

  ```` Cube * s1; ```` // a pointer to a variable of type Cube

  #### Pointers and References
  > a ptr has its own memory addr and size on the run time stack

  > a reference shares the same memory addr (w the original variable) but also takes up its own 'spot' in the run time stack

  ```
  int i = 3;
  int *ptr = &i; // a ptr to variable 'i'. ptr stores addr of i
  int &ref = i;  // a reference (or alias) for i
  ```

  ```` Initialization of a pointer variable ````
  ```
  int  a = 10;
  int *p = &a; // do not do it this way. looks weird becuz p = &a is better

  OR

  int  a = 10;
  int *p;
  p = &a;   // value of 'p' = addr of 1
  print(*p) // prints the dereferenced '*p' value at the addr of &a 
  ```

  > pointers can be re-assigned. 
  ```
  int a = 5;
  int b = 6;
  int *p;
  p =  &a;
  p = &b;
  ```

  ```` Initialization of a reference variable ````
  ```
  int  a = 10;
  int &p = a; // addr of p takes the value of 10
  ```

  > references canNOT be re-assigned: ERROR for MULTIPLE DECLARATION
  ```
  int a = 5;
  int b = 6;
  int &p = a;
  int &p = b; 
  ```

  #### Indirection Operators
  > You can have pointers to pointers offering extra levels of indirection
  ```
  int  a = 10;
  int *p;
  int **q;
  p = &a;   // value of 'p' = addr of a
  q = &p;   // value of 'q' = addr of p

  ```

  > Whereas references only offer one level of indirection
  ```
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
  
  ### Lecture : 4 Heap Memory
  <details> <summary> <span style="color: green"> Lecture 4 </span></summary>

  #### Heap Memory Description
  > Starts near bottom of memory (low addr) -> Data grows upward -> Ends at top of memory (high addr)

  ```` 'new' keyword ```` creates heap memory (returns a ptr to the 'new' memory created)
  > allocates heap mem, calls obj's constructor, and returns a ptr to the memory

  ```` 'delete' keyword ```` frees ('deletes') the heap memory
  > calls obj's destructor, marks mem as freed

  ```` heap1.cpp ````
  ```
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
  ```
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
  ```
  int a = 3
  int & b = a;        //declaring a reference variable  

  ```

  > this process should not be confused with the case of getting the memory address of a variable which would also involved with '&' operator, as the example shown below:
  ```` REFERENCE INIT: no space in between & and variable name ````
  ```
  Cube c;
  std::cout << "Mem address storing c: " << &c << std::endl;

  ```

  #### 

  </details>

  ### Lecture : 5 Function & Parameter
  <details> <summary> <span style="color: green"> Lecture 5 </span></summary>

  #### Function Parameters
  > There are 3 ways to pass an arguement to a function
  ##### pass by value 
  the obj passed in it a copy of the original obj. By changing it, we do not change the original. Less efficient because it needs extra memory

  ```` joinCubes-byValue.cpp ````
  ```
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



  ##### pass by reference
  the obj passed in is an alias of the original obj. By changing it, we do change the original. More efficient because we treat the memory. But more risky because we are changing the original value

  ```` joinCubes-byRef.cpp ````
  ```
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

  #### The 'const' Function Parameter


  #### 

  #### 

  </details>

  ### Lecture : 5 Function & Parameter
  <details> <summary> <span style="color: green"> Lecture 5 </span></summary>

  #### Function Parameters
  
  #### The 'const' Function Parameter

  #### 

  #### 

  </details>


</details>

<details> <summary> Click for Labs </summary>
  
  ### Lecture 1: Introduction
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
  ```
  #ifndef CUBE_H_ 
  #define CUBE_H_

  class Cube {
    public:
    private:
  };

  #endif 
  ```

  ```
  #pragma once

  class Cube {
    public:
    private:
  };
  ```
  
  #### Scope Resolution Opperator
  > 'double Cube::getVolume(){ . . . }' in Cube.cpp allows us to implement the getVolume() method in the Cube class
  
  </details>

  ### Lecture 2: Classes
  <details> <summary> <span style="color: green"> Lecture 2 </span></summary>

  #### Public vs Private
  > Public variables are members of classes that can be accessed from the outside of the class

  > Private variables are members of classes that can only be used within the class's functions and cannot be viewed outside the classes

  #### Namespace
  > Namespaces are like Libraries in C++. std = standard namespace includes cout, vector, queue,
  
  ```` cs225::Cube: ```` cs225 namespace includes Cube, PNG, HSLAPixel, etc

  ```` std::cout ```` standard namespace includes cout, vector, queue, etc

  ```` // cube.h declares namespace class Cube````
  ```
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
  ```
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
  ```
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
  ```
  /* ... */
  class Cube{
    public:
    Cube (); // default constructor
    Cube (double r); // custom constructor
  /* ... */
  ```
  ```` // cube.cpp ````
  ```
  /* ... */

  Cube::Cube() { //define default constructor
      radius_ = 1;
  }
  Cube::Cube(double r) { //define custom constructor
      radius_ = r;
  }
  ```
  ```` // main.cpp ````
  ```
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
```
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

  ### Lecture 3: Memory
  <details> <summary> <span style="color: green"> Lecture 3 </span></summary>

  #### Variable, Reference Variables, Pointers

  ```` Cube   s1; ```` // a variable containing a Cube obj

  ```` Cube & s2; ```` // a reference to a variable of type Cube

  ```` Cube * s1; ```` // a pointer to a variable of type Cube

  #### Pointers and References
  > a ptr has its own memory addr and size on the run time stack

  > a reference shares the same memory addr (w the original variable) but also takes up its own 'spot' in the run time stack

  ```
  int i = 3;
  int *ptr = &i; // a ptr to variable 'i'. ptr stores addr of i
  int &ref = i;  // a reference (or alias) for i
  ```

  ```` Initialization of a pointer variable ````
  ```
  int  a = 10;
  int *p = &a; // do not do it this way. looks weird becuz p = &a is better

  OR

  int  a = 10;
  int *p;
  p = &a;   // value of 'p' = addr of 1
  print(*p) // prints the dereferenced '*p' value at the addr of &a 
  ```

  > pointers can be re-assigned. 
  ```
  int a = 5;
  int b = 6;
  int *p;
  p =  &a;
  p = &b;
  ```

  ```` Initialization of a reference variable ````
  ```
  int  a = 10;
  int &p = a; // addr of p takes the value of 10
  ```

  > references canNOT be re-assigned: ERROR for MULTIPLE DECLARATION
  ```
  int a = 5;
  int b = 6;
  int &p = a;
  int &p = b; 
  ```

  #### Indirection Operators
  > You can have pointers to pointers offering extra levels of indirection
  ```
  int  a = 10;
  int *p;
  int **q;
  p = &a;   // value of 'p' = addr of a
  q = &p;   // value of 'q' = addr of p

  ```

  > Whereas references only offer one level of indirection
  ```
  int  a = 10;
  int *p;
  p = &a;   // value of 'p' = addr of 1
  &p = a;   // the addr of 'p' = the value of a = the value of 10

  //       val of p   (p) = addr of a
  //       addr of p (&p) = val of a, 10
  // deref val of *p (*p) = val of a, 10
  ```


  #### Stack Memory
  > 

  #### Stack Frames
  > 


  </details>
  
  ### Lecture 4: Classes
  <details> <summary> <span style="color: green"> Lecture 4 </span></summary>

  #### Public vs Private
  
  #### Namespace

  #### Constructor

  #### Reference Variables


  </details>


</details>


<details> <summary> Click for ALL NOTES </summary>
  
  <details> <summary> Lecture 1: Introduction </summary>

  ## Lecture 1: Introduction
    
  <details> <summary> Variables </summary>

  ### Variables
  - Variables in C++ are defined by 
    ```` (1) Name ````
    ```` (2) Type ````
    ```` (3) Locations (in memory) ````
    ```` (4) Value ````
    
  - Variable Types can be Primitive
    ```` int ````
    ```` char ````
    ```` double ````
    ```` boolean ````
    ```` float ````
    ```` pointer ````
    
  - Or Variable Types can be User Defined
    ```` Use classes to define new vars ````

  </details>

  <details> <summary> Variables </summary>

  ### Variables
  - Variables in C++ are defined by 
    ```` (1) Name ````
    ```` (2) Type ````
    ```` (3) Locations (in memory) ````
    ```` (4) Value ````
    
  - Variable Types can be Primitive
    ```` int ````
    ```` char ````
    ```` double ````
    ```` boolean ````
    ```` float ````
    ```` pointer ````
    
  - Or Variable Types can be User Defined
    ```` Use classes to define new vars ````

  </details>



  </details>
</details>


### Encapsulation:
| cube.h | cube.cpp |
| --- | --- |
|Interface/API (What the class is supposed to do) | Implementation (how the class is supposed to do it) |	

### Inclusion Guards
CUBE.H: #pragma once vs #ifndef	
	
```` // cube.h w/ #ifndef ````
```
#ifndef CUBE_H_ 
#define CUBE_H_

class Cube {
     public:
     private:
};

#endif 
```
```` // cube.h w/ #pragma once ````
```
 #pragma once

class Cube {
     public:
     private:
};
```

## Lecture 2: Classes
### Private vs Public Variables
| Private | Public |
| --- | --- |
| can only be accessed inside of its own class | can be accessed from outside class (in main)

### NameSpace
Namespaces are like Libraries. ```` std: cout vector queue, etc ```` ```` CS225: Cube, PNG, HSLAPixel, etc ````

```` // cube.h declares namespace class Cube````
```
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
```
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
```
#include “Cube.h”
#include <iostream>

int main() {
    cs225::Cube c; // declares obj of cube type
    std::cout << "Volume: " <<    c.getVolume() << std::endl;
    return 0;
}
	
```

## Constructors
- Default Constructor: ```` no parameter ```` ```` initializes the class value to default values ````
- Customized Constructors: ```` user may set the initialization ````

```` // cube.h ````
```
/* … */
class Cube{
	public:
	Cube (); // default constructor
	Cube (double s); // custom constructor
/* … */
```
```` // cube.cpp ````
```
/* … */

Cube::Cube() { //define default constructor
     radius_ = 1;
}
Cube::Cube(double r) { //define custom constructor
     radius_ = r;
}
```

## Reference Variables
- aliases is used to bound two values together. 
- once the value of j changes, the value of i changes changes and vice versa

```` main.cpp ````
```
int main {
     int i = 7;
     int &j = i;   	// j is an alias of i
     j = 4;		// j and i are both 4 
     std::cout << i << “ ” << j << std::endl;   
     i = 2;		// j and i are both 2
     std::cout << i << “ ” << j << std::endl;   
     return 0;
}
```
	
## Lecture 3: Pointers and Memory
### Variables, Reference Variables, Pointers
```
Cube    s1;  // a variable containing a Cube object
Cube &  s2; // a reference to a variable of type Cube
Cube *  s3; // a pointer to a variable of type Cube
```
### Pointers
```` pa = &a; ````
```
LEA R0, a  ; get the address of the variable
ST  R0, pa ; store it in the pointer variable
```

```` b = *a; ````
```
LDI R0, pa ; get the value at the address stored in pa
ST  R0, b  ; store it in b	
```	

```` *pa = b; ````
```
LD  R0, b   ; load the value of b
STI R0, pa  ; store it at the address stored in pa	
```	
	
```
int main() {
   cs225::Cube c;
   cs225::Cube *ptr = &c;
	
   std::cout << "Address storing `c`:" << &c << std::endl;   // addr of c
   std::cout << "Addr. storing ptr: "<< &ptr << std::endl;   // &ptr == addr of c
   std::cout << "Contents of ptr: "<< ptr << std::endl;
}
	
```
	
</details>

# Labs
Below are all the information about the changes I made on the labs

<details>
	<summary> Click for lab_intro </summary>
	<p>
#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```
	</p>
</details>
<details>
	<summary> Click for lab_debug </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for lab_memory </summary>
	<p>
#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```
	</p>
</details>
<details>
	<summary> Click for lab_inheritance </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for lab_quacks </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for lab_trees </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for lab_huffman </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for lab_avl </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for lab_btree </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for lab_hash </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for lab_heaps </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for lab_dict </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>


# Machine Problems (MPs)
Below are all the information about the changes I made on the Machine Problems
<details>
	<summary> Click for mp_intro </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for mp_stickers </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for mp_lists </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for mp_traversals </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for mp_mosaics </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
<details>
	<summary> Click for mp_mazes </summary>
	<p>

#### We can hide anything, even code!

    ```ruby
      puts "Hello World"
    ```

	</p>
</details>
