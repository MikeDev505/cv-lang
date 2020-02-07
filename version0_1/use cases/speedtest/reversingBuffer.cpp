#include <iostream>
#include <chrono>

using namespace std;

//simple aprouch
// long long return and j is to avoid aggressive optimization
long long reverseBuffor(char* buffor, int len, long long j)
{
  int ret = 0;
  
  int end=len-1;
  for(int start=0; start<end; start++, end--)
  { 
    char temp = buffor[start];
    buffor[start] = buffor[end];
    buffor[end] = temp;
  }
  
  return ret;
}

// Fast verison used pointers
// long long return and j is to avoid aggressive optimization
long long reverseBufforFast(char* buffor, int len, long long j)
{
  char* start = buffor;
  char* end = &buffor[len-1];
  int ret = 0;
  
  while(start <= end)
  { 
    char temp = *start;
    *start = *end;
    *start = temp;
    start++;
    end--;
  }
  
  return ret;
}


// Fastes verison used pointers and develop of inner loop
// long long return and j is to avoid aggressive optimization
long long reverseBufforFastFast(char* buffor, int len, long long j)
{
  char* start = buffor;
  char* end = &buffor[len-1];
  long long ret = 0;
  
  while(start <= end)
  { 
    char temp = *start;
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
    
    *start = *end;
    *start = temp;
    start++;
    end--;
    ret+=temp+j;
  }
  
  return ret;
}


int main() {
    char bufor[10000];
    long long sumaRet=0;
    
    //init buffer to avoid aggressive optimization
    for(int i=0; i< sizeof(bufor); i++)
    {
        bufor[i] = i%200;
    }
    
    auto t0 = std::chrono::high_resolution_clock::now();
    //testing execution loop
    for(long long i=0; i<10000;i++)
    {
        sumaRet += reverseBufforFastFast(bufor, sizeof(bufor),i);
    }    
    auto t1 = std::chrono::high_resolution_clock::now();    
    
  
  
  
    int sum = 0;
    //sum buffer to avoid aggressive optimization
    for(int i=0; i< sizeof(bufor); i++)
    {
        sum += bufor[i];
    }
    
    cout << sumaRet << "\n";

  std::chrono::duration< double > fs = t1 - t0;
  std::chrono::milliseconds d = std::chrono::duration_cast< std::chrono::milliseconds >( fs );

  std::cout << fs.count() << "s\n";
  std::cout << d.count() << "ms\n";
}
