/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225 {

  // def constructor
  HSLAPixel::HSLAPixel(){ 
    h = 1;
    s = 1;
    l = 1;
    a = 1;
  }
  
  // custom constructor
  HSLAPixel::HSLAPixel(double hue, double saturation, double luminance){  
    h = hue;
    s = saturation;
    l = luminance;
    a = 1;
  } 

  // custom constructor
  HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha){
    h = hue;
    s = saturation;
    l = luminance;
    a = alpha;    
  }

  double h; // hue: [0,360]
  double s; // saturation: [0,1]
  double l; // luminance: [0,1]
  double a; // alpha: [0,1]
}
