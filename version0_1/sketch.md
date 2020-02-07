# Example

``` C#
class Person
{
  string Name {get;set;}
}

void saveFunction(object[] params)
{
}

T addFunctionTemplate<T>(T a,T b)
{
  return a+b;
}

void swapBuffor(byte* buffor, int len)
{
  byte* start = bufor;
  byte* end = &bufor[len-1];
  
  for(int i=0; i< len/2; i++)
  { 
    var temp = *start;
    *start = *end;
    *start = temp;
    start++;
    end--;
  }
}

//faster if big buffer 
void swapBufferFast<int t=10>(byte* buffor, int len)
{  
  byte* start = bufor;
  byte* end = &bufor[len-1];
    
  for(int i=0; i< len/2; i++)
  {
    var temp = *start;  
    @(for(int i=0; i<t; i++) //this is executet on before compilation time - like template
    {
      *start = *end;
      *start = temp;
      start++;
      end--;
    })
  }
}


string buissnesFunction1(string name, int a, double b)
{
  int i; // error in compilation in fast context not initialized -
  saveFunction(name, a);
  saveFunction(a,b,i);
  i = 123;
  saveFunction(a,b,i);
  
  var person = new Person();
  saveFunction(person);
}

void main()
{
  using(var c = new SafeContext())
  {
    buissnesFunction1("dfsf", 1, 2);
  }
  
  using(var c = new FastContext())
  {
    buissnesFunction1("dfsf", 1, 2);
  }
}

```
