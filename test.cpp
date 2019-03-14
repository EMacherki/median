

// Run: g++ test.cpp -o lsd_test 

#include "median.h"
#include <iostream>




using namespace std;


int main (){
 
  cout<<endl;
  cout<<endl;
  cout<< "* -This a test of median arithmetic" <<endl;
  cout<< "* -The algorithm is a hybrid of MSD radix sort, written with C++ and dezigned to IntegerSort R package" <<endl;
  cout<<endl;
  cout<<endl;
  cout<< "*** Created by :         MACHERKI M. E. 2019" <<endl;
  cout<<endl;
  cout<<endl;
  
  
  
  int x_size=14;
  int x[]={88,11,77,-5,99,12,3654,88,6547,2301,-9658,785418544,-23145,-988566421};
  // the median of this sample is 82.5
  cout<< "* -Data simple   :" <<endl<<endl;
  for(int i=0;i<x_size;i++) cout<<"  "<<x[i];
  unsigned *tmp=(unsigned *)x;
  median (tmp,tmp+x_size);
  cout<<endl<<endl;
  cout<< "* -after running the algorithm " <<endl<<endl;
  cout<<"* -The median is   :"<<median (tmp,tmp+x_size)<<endl;
  cout<< "DONE" <<endl; 
  
}