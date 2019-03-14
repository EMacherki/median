
/*
 MIT License
Copyright (c) [2019] [Med Ezzeddine Macherki]
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#define  INTMIN  -2147483648u



int p_int_odd (unsigned *l, unsigned *r, int k){
  
  int count[0x10000]={0};
  for(unsigned *i=l;i!=r;i++) count[(*i-INTMIN) >>16]++;
  unsigned f=0;int pos=k+1;
  while(count[f]<pos) pos-=count[f++];
  
  for(int i=0;i<0x10000;i++)count[i]=0; // reset count to 0
  for(unsigned *i=l;i!=r;i++)
    if((*i-INTMIN)>>16==f)count[(*i-INTMIN)& 0xffff]++;
  
  unsigned b=0;
  while(count[b]<pos) pos-=count[b++];
  return ((f<<16)+b)+INTMIN;
  
  
}

double p_int_pair (unsigned *l, unsigned *r, int k){
  
  int count[0x10000]={0};
  for(unsigned *i=l;i!=r;i++) count[(*i-INTMIN) >>16]++;
  unsigned f=0;int pos=k;
  while(count[f]<pos) pos-=count[f++];
  unsigned f1=0; int pos1=k+1;
  while(count[f1]<pos1) pos1-=count[f1++];
  if(f==f1){
    
  for(int i=0;i<0x10000;i++)count[i]=0; // reset count to 0
  for(unsigned *i=l;i!=r;i++)
    if((*i-INTMIN)>>16==f)count[(*i-INTMIN)& 0xffff]++;
    
    unsigned b=0;
    while(count[b]<pos) pos-=count[b++];
    unsigned b1=0;
    while(count[b1]<pos1) pos1-=count[b1++];
    
    int v1=(f<<16)+b+INTMIN;
    int v2=(f<<16)+b1+INTMIN;
    
    return  ((double)v1+(double)v2)/(double)2;;
  }
  
  for(int i=0;i<0x10000;i++)count[i]=0; // reset count to 0
  for(unsigned *i=l;i!=r;i++)
    if((*i-INTMIN)>>16==f)count[(*i-INTMIN)& 0xffff]++;
    
    unsigned b=0;
    while(count[b]<pos) pos-=count[b++];
    
    for(int i=0;i<0x10000;i++)count[i]=0; // reset count to 0
    for(unsigned *i=l;i!=r;i++)
      if((*i-INTMIN)>>16==f1)count[(*i-INTMIN)& 0xffff]++;
      
      
    unsigned b1=0;
    while(count[b1]<pos1) pos1-=count[b1++];
    int  v1=(f<<16)+b+INTMIN;
    int  v2=(f1<<16)+b1+INTMIN;
    return  ((double)v1+(double)v2)/(double)2;;
    
    
}


double median(unsigned *l, unsigned *r){ 
  int N=r-l;
  if(N==1) return *l; // unique value
  if(N==2) return ((double)*l+(double)*(l+1))/(double)2; //two value
  if(N %2) return p_int_odd(l,r,(N/2));
           return p_int_pair(l,r,N/2);
  
}

