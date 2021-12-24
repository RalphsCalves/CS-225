# CS-225
Data Structures. Enjoy these labs and mps, and please do not pull an all nighter for the labs.

# Understanding Data Structures
Below are the notes that I took for Data Structures @UIUC.

<details> <summary> Click for ALL NOTES </summary>
  
  ## Lectures:

  <details> <summary> Lecture 1 </summary>

  ### Lecture 1: Introduction
    
  <details> <summary> Variables </summary>

  ### Variables
  - Variables in C++ are defined by 
    ```` (1) Name ````

  </details>

  <details> <summary> Booleans </summary>

  ### Other Stuff
  - Variables in C++ are defined by 
    ```` (1) Name ````

  </details>

  </details>

  <details> <summary> Lecture 2 </summary>

  ## Lecture 1: Introduction
    
  <details> <summary> Variables </summary>

  ### Variables
  - Variables in C++ are defined by 
    ```` (1) Name ````

  </details>

  <details> <summary> Booleans </summary>

  ### Other Stuff
  - Variables in C++ are defined by 
    ```` (1) Name ````

  </details>

  </details>
  


</details>



<details> <summary> Click for ALL NOTES </summary>
  
  <details> <summary> Lecture 1 </summary>

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
